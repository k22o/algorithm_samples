#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)
using ipair = pair<ll,ll>;

//https://atcoder.jp/contests/abc091/tasks/arc092_a

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
    ll N;
    cin >> N;
    ll nodeNum = N+N+2;
    E.assign(nodeNum,vector<edge>{});

    vector<ipair> red(N),blue(N);
    rep(i,0,N) cin >> red[i].first >> red[i].second;
    rep(i,0,N) cin >> blue[i].first >> blue[i].second;
    sort(red.begin(),red.end());
    sort(blue.begin(),blue.end());

    //条件を満たすノードを追加
    rep(i,0,N){//blue
        rep(j,0,N){//red
            if(blue[i].first<=red[j].first) break;
            else if(blue[i].second>red[j].second) add_edge(i,N+j,1);
        }
    }
    //start[2N] -> blue -> red -> end[2N+1]
    rep(i,0,N){
        add_edge(nodeNum-2,i,1);
        add_edge(N+i,nodeNum-1,1);
    }

    cout << edmonds_karp(nodeNum-2,nodeNum-1) << endl;
}
