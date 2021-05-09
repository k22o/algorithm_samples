#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)
using ipair = pair<ll,ll>;


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
    return ans;
}

int main(){
    ll V,M,F,u,v,c,d;
    cin >> V >> M >> F;
    E.assign(2*V+2,vector<edge>{});
    rep(i,0,M){
        cin >> u >> v >> d;
        add_edge(u,V+v,1,-d);
    }
    rep(i,0,V){
        add_edge(2*V,i,1,0);
        add_edge(V+i,2*V+1,1,0);
    }
    cout << -1*min_cost_ssp(2*V,2*V+1,F) << endl;
}

/*
3 9 3
0 0 2
0 1 4
0 2 5
1 0 5
1 1 1
1 2 3
2 0 6
2 1 2
2 2 3

ans:13
*/
