#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)
using ipair = pair<ll,ll>;

//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B&lang=jp

struct edge{ll to,cap,cost,rev;};
vector<vector<edge>> E;
vector<ll> pred;

void add_edge(ll u,ll v, ll cap, ll cost){
    E[u].push_back(edge{v,cap,cost,(ll)E[v].size()});
    E[v].push_back(edge{u,0,-cost,(ll)E[u].size()-1});
}

ll bellman_ford(ll N, ll start, ll goal){
    pred.assign(N,-1);    
    vector<ll> dist(N,INF);
    dist[start]=0;
    for(ll loop=0;loop<N;loop++){
        for(ll i=0;i<N;i++){
            for(edge e:E[i]){
                if (dist[i]==INF) continue;
                if(e.cap>0 && dist[i]+e.cost<dist[e.to]){
                    dist[e.to] = dist[i] + e.cost;
                    pred[e.to] = i;
                }
            }
        }
    }
    return dist[goal];
}


ll update(ll s, ll t, ll maxF){
    ll u,v,delta = INF;//増加分
    //最小の増加量をtargetから遡って探す
    v = t;
    while(v!=s){
        ll tmp = INF;
        u = pred[v];
        for(auto &e:E[u]) if(e.to==v && e.cap>0){tmp = e.cap;break;}
        delta = min({delta,tmp,maxF});
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

ll min_cost_ssp(ll s, ll t, ll maxF){
    ll res = maxF;
    ll ans = 0;
    while(res>0){
        ll findCost = bellman_ford((ll)E.size(),s,t);
        if(findCost==INF) break;
        ll delta = update(s,t,res);
        ans += findCost * delta;
        res -= delta;
    }
    if(res!=0) return -1;
    return ans;
}

int main(){
    ll V,M,F,u,v,c,d;
    cin >> V >> M >> F;
    E.assign(V,vector<edge>{});
    rep(i,0,M){
        cin >> u >> v >> c >> d;
        add_edge(u,v,c,d);
    }
    ll ans = min_cost_ssp(0,V-1,F);
    cout << ans << endl;
}

/*
6 9 6
0 1 8 3
0 2 5 2
1 2 37 7
1 3 4 3
2 3 3 4
2 4 9 2
3 4 56 9
3 5 9 6
4 5 2 1

ans:58
*/