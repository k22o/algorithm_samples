#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using namespace std;
#define INF 1000000000000000LL
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)
using ipair = std::pair<ll,ll>;
using itpl = std::tuple<ll,ll,ll>;

//https://atcoder.jp/contests/abc164/tasks/abc164_e
struct Edge{
    ll to, weight,value;
};

vector<vector<ll>> dist;
vector<vector<Edge>> edgeVec;// edge[u]:uから繋がるEdge

void dijkstra(ll N, ll startSite, ll startValue,ll coinMax){
    if(startValue>coinMax) startValue = coinMax;
    dist[startSite][startValue]=0;
    priority_queue<itpl,vector<itpl>,greater<itpl>> que;
    que.push(make_tuple(0,startSite,startValue));
    while(!que.empty()){
        ll nowDist,preSite,preValue;
        tie(nowDist,preSite,preValue) = que.top();
        que.pop();
        //if(nowDist>dist[pre]) continue;
        for(Edge e :edgeVec[preSite]){
            if(preValue>=e.value && dist[e.to][preValue-e.value]>dist[preSite][preValue]+e.weight){
                ll tmp = (preValue-e.value)>coinMax ? coinMax : (preValue-e.value);
                dist[e.to][tmp] = dist[preSite][preValue] + e.weight;
                que.push(make_tuple(dist[e.to][tmp],e.to,tmp));
            }
        }
    }
}

int main() {
    ll n,m,s,t;// Node num, Edge num, start point ,goal point
    cin >> n >> m >> s;
    edgeVec.assign(n,vector<Edge>{});
    ll u,v,a,b,c,d,coinMax=0;
    
    rep(i,0,m){ 
        cin >> u >> v >> a >>b;
        u --; v --;
        edgeVec[u].push_back(Edge{v,b,a});
        edgeVec[v].push_back(Edge{u,b,a});
        if(a>coinMax) coinMax = a;
    }
    coinMax = (n-1)*coinMax;
    dist.assign(n,vector<ll>(coinMax+1,INF));

    rep(i,0,n){
        cin >>c >>d;
        edgeVec[i].push_back(Edge{i,d,-1*c});
    }
    dijkstra(n,0,s,coinMax);

    rep(i,1,n){
        ll ans = INF;
        rep(j,0,dist[0].size()){if(ans>dist[i][j]) ans = dist[i][j];}
        cout << ans << endl;
    }
}