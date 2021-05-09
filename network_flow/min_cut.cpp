#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)

//https://atcoder.jp/contests/abc010/tasks/abc010_4

struct edge{ll to,cap,rev;};
vector<vector<edge>> E;
vector<ll> pred;

void add_edge(ll u,ll v, ll cap){
    E[u].push_back(edge{v,cap,(ll)E[v].size()});
    E[v].push_back(edge{u,0,(ll)E[u].size()-1});
}

//幅優先探索
ll search(ll s, ll t){
    ll N = E.size();
    pred.assign(N,-1);    
    queue<ll> que; que.push(s);
    while(!que.empty()){
        ll u = que.front(); que.pop(); 

        for(edge e:E[u]){
            if(e.cap>0 && pred[e.to]==-1){
                pred[e.to] = u;
                if (e.to== t) return true;
                que.push(e.to);
            }
        }
    }
    return false;
}

ll update(ll s, ll t){
    ll u,v,delta = INF;//増加分
    //最小の増加量をtargetから遡って探す
    v = t;
    while(v!=s){
        ll tmp = INF;
        u = pred[v];
        for(auto &e:E[u]) if(e.to==v && e.cap>0){tmp = e.cap;break;}
        delta = min(delta,tmp);
        v = u;
    }

    //求まった増加量を実際のネットワークに反映させる
    v = t;
    while(v!=s){
        u = pred[v];
        for(auto &e:E[u]){
            if(e.to==v && e.cap>0){
                e.cap -= delta;
                E[e.to][e.rev].cap += delta;
                break;
            }
        }
        v = u;
    }   
    return delta;
}

ll edmonds_karp(ll s, ll t){
    ll ans = 0;
    while(1){
        bool flag = search(s,t);
        if(!flag) break;
        else ans += update(s,t);
    }
    return ans;
}

int main(){
    ll N,G,M,u,v;
    cin >> N >> G >> M;
    E.assign(N+1,vector<edge>{});
    vector<ll> p(G);
    rep(i,0,G) cin >> p[i];
    rep(i,0,M){
        cin >> u >> v;
        if(u==0) add_edge(u,v,1);
        else if (v==0) add_edge(v,u,1);
        else{
            add_edge(u,v,1);
            add_edge(v,u,1);
        }
    }
    rep(i,0,G) add_edge(p[i],N,1);
    cout << min(edmonds_karp(0,N),G) << endl;

}
