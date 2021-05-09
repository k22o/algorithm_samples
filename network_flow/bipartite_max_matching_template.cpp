#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)

//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A&lang=jp

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
    ll X,Y,M,u,v;
    cin >> X >> Y >> M;
    ll nodeNum = X+Y+2;
    E.assign(nodeNum,vector<edge>{});

    rep(i,0,M){
        cin >> u >> v ;
        add_edge(u,X+v,1);
    }
    rep(i,0,X) add_edge(nodeNum-2,i,1);
    rep(i,0,Y) add_edge(X+i,nodeNum-1,1);

    cout << edmonds_karp(nodeNum-2,nodeNum-1) << endl;
}

/*
sample
6 6 8
0 0
1 1
1 3
1 4
2 5
3 2
4 2
5 5

ans:4
*/