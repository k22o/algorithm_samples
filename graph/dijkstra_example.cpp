#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using namespace std;
#define INF 1000000000000000LL
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)
using ipair = std::pair<ll,ll>;

//https://atcoder.jp/contests/soundhound2018-summer-qual/tasks/soundhound2018_summer_qual_d
struct Edge{
    ll to, weight;
};

vector<ll> dist1,dist2;//,pred;
vector<vector<Edge>> edgeVec1,edgeVec2;// edge[u]:uから繋がるEdge

void dijkstra1(ll N, ll start){
    dist1[start]=0;
    priority_queue<ipair,vector<ipair>,greater<ipair>> que;
    que.push(make_pair(0,start));
    while(!que.empty()){
        ll nowDist,pre;
        tie(nowDist,pre) = que.top();
        que.pop();
        if(nowDist>dist1[pre]) continue;
        for(Edge e :edgeVec1[pre]){
            if(dist1[e.to]>dist1[pre]+e.weight){
                dist1[e.to] = dist1[pre] + e.weight;
                //pred[e.to] = pre;
                que.push(make_pair(dist1[e.to],e.to));
            }
        }
    }
}

void dijkstra2(ll N, ll start){
    dist2[start]=0;
    priority_queue<ipair,vector<ipair>,greater<ipair>> que;
    que.push(make_pair(0,start));
    while(!que.empty()){
        ll nowDist,pre;
        tie(nowDist,pre) = que.top();
        que.pop();
        if(nowDist>dist2[pre]) continue;
        for(Edge e :edgeVec2[pre]){
            if(dist2[e.to]>dist2[pre]+e.weight){
                dist2[e.to] = dist2[pre] + e.weight;
                //pred[e.to] = pre;
                que.push(make_pair(dist2[e.to],e.to));
            }
        }
    }
}


int main() {
    ll n,m,s,t;// Node num, Edge num, start point ,goal point
    cin >> n >> m >> s>> t;
    dist1.assign(n,INF);
    dist2.assign(n,INF);
    edgeVec1.assign(n,vector<Edge>{});
    edgeVec2.assign(n,vector<Edge>{});

    ll u,v,a,b;
    rep(i,0,m){
        cin >> u >> v >> a >> b;
        u --; v--;
        edgeVec1[u].push_back(Edge{v,a});
        edgeVec1[v].push_back(Edge{u,a});
        edgeVec2[u].push_back(Edge{v,b});
        edgeVec2[v].push_back(Edge{u,b});
    }

    ll money = 1e15;
    dijkstra1(n,s-1);
    dijkstra2(n,t-1);
    vector<ll> sumDist(n),ans(n);
    rep(i,0,n) sumDist[i] = dist1[i]+dist2[i];

    ll mi = sumDist[n-1];
    for(ll i=n-1;i>=0;i--){
        mi = min(mi,sumDist[i]);
        ans[i] = money - mi;
    }

    for(ll i=0;i<n;i++){
        cout << ans[i] << endl;
    }
}