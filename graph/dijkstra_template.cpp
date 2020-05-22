#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using namespace std;
#define INF 1000000000000000LL
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)
using ipair = std::pair<ll,ll>;

//http://poj.org/problem?id=3255
struct Edge{
    ll to, weight;
};

vector<ll> dist,pred;
vector<vector<Edge>> edgeVec;// edge[u]:uから繋がるEdge

void dijkstra(ll N, ll start){
    dist[start]=0;
    pred[start]=-1;
    priority_queue<ipair,vector<ipair>,greater<ipair>> que;
    que.push(make_pair(0,start));
    while(!que.empty()){
        ll nowDist,pre;
        tie(nowDist,pre) = que.top();
        que.pop();
        if(nowDist>dist[pre]) continue;
        for(Edge e :edgeVec[pre]){
            if(dist[e.to]>dist[pre]+e.weight){
                dist[e.to] = dist[pre] + e.weight;
                pred[e.to] = pre;
                que.push(make_pair(dist[e.to],e.to));
            }
        }
    }
}

int main() {
    ll n,m,s,g;// Node num, Edge num, start point ,goal point
    cin >> n >> m;
    s=0;
    g=n-1;
    dist.assign(n,INF);
    pred.assign(n,INF);
    edgeVec.assign(n,vector<Edge>{});
    ll u,v,w;
    rep(i,0,m){
        cin >> u >> v >> w;
        u --; v--;
        edgeVec[u].push_back(Edge{v,w});
        edgeVec[v].push_back(Edge{u,w});
    }
    dijkstra(n,s);
    cout << dist[g]<<endl;
}