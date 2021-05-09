#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)
using ipair = pair<ll,ll>;
using ppair = pair<ll,ipair>;

https://atcoder.jp/contests/maximum-cup-2013/tasks/maximum_2013_f

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
    ll N,M;
    string S;
    cin >> N >> M;
    vector<ipair> K(N,make_pair(0,0));
    vector<ppair> Ma(M,make_pair(0,make_pair(0,0)));
    rep(i,0,N) cin >> S >> K[i].first >> K[i].second;
    rep(i,0,M) cin >> S >> Ma[i].first >>Ma[i].second.first >> Ma[i].second.second;

    ll thres = Ma[min(N,M)-1].first;   
    sort(Ma.begin(),Ma.end(),greater<ppair>());
    
    if(M>N){
        ll idx=N;
        while(Ma[idx].first==thres) idx++;        
        Ma.erase(Ma.begin()+idx,Ma.end());
    }

    M = Ma.size();
    E.assign(N+M+3,vector<edge>{});
    ll start = N+M;
    ll fin_f = N+M+1;
    ll fin = N+M+2,cnt=0;

    rep(i,0,N){
        rep(j,0,M){
            if(Ma[j].first==0) continue;
            add_edge(i,N+j,1,(abs(K[i].first-Ma[j].second.first)+abs(K[i].second-Ma[j].second.second)));
        }
    }

    rep(i,0,N) add_edge(start,i,1,0);
    rep(j,0,M){
        if(Ma[j].first>thres){add_edge(N+j,fin,1,0);cnt++;}
        else {add_edge(N+j,fin_f,1,0);}
    }
    add_edge(fin_f,fin,min(N,M)-cnt,0);
    cout << min_cost_ssp(start,fin,min(N,M)) << endl;
}
