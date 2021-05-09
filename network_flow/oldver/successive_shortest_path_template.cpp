#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)
using ipair = pair<ll,ll>;

//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B&lang=jp

vector<vector<ll>> capacity;
vector<vector<ll>> flow,cost;
vector<ll> pred;

ll bellman_ford(ll N, ll start, ll goal){
    vector<ll> dist(N,INF);
    dist[start]=0;
    for(ll loop=0;loop<N;loop++){
        for(ll i=0;i<N;i++){
            for(ll j=0;j<N;j++){
                if (dist[i]==INF || capacity[i][j]==0) continue;
                if(capacity[i][j]-flow[i][j]>0 && dist[i]+cost[i][j]<dist[j]){
                    dist[j] = dist[i] + cost[i][j];
                    pred[j] = i;
                }
            }
        }
    }
    return dist[goal];
}

//増加させることができる経路を探し，flowを1流す際のコストを返す
//可能経路は，predに保存される ex. pred[v] = u ... u->vの経路
ll findPath(ll s, ll t){
    ll N = capacity.size();
    pred.assign(N,-1);
    return bellman_ford(N,s,t);
}

//ネットワークを更新し，増加分を返す．
ll update(ll s, ll t, ll maxF){
    ll tmp,u,v,delta = INF;//増加分
    //最小の増加量をtargetから遡って探す
    v = t;
    while(v!=s){
        u = pred[v];
        if(capacity[u][v]>0) tmp = capacity[u][v] -flow[u][v];
        else if (capacity[v][u]>0) tmp = flow[v][u];
        delta = min({delta,tmp,maxF});
        v = u;
    }
    //求まった増加量を実際のネットワークに反映させる
    v = t;    
    while(v!=s){
        u = pred[v];
        if(capacity[u][v]>0) flow[u][v] += delta;
        else if (capacity[v][u]>0) flow[v][u] -= delta;
        v = u;
    }
    return delta;
}

//増加経路を探索し，見つかったら更新する
ll min_cost_ssp(ll s, ll t, ll maxF){    
    ll res = maxF;//残り流す量
    ll delta,tmpCost;//増加分,そのルートでかかるコスト
    ll ans = 0;
    while(1){
        tmpCost = findPath(s,t);
        if(tmpCost==INF) break;
        delta = update(s,t,res);
        ans += delta * tmpCost;
        res = res-delta;
        //if(res==0) break;
    }
    return ans;
}
int main(){
    ll V,E,F,u,v,c,d;
    cin >> V >> E >> F;
    capacity.assign(V,vector<ll>(V,0));
    flow.assign(V,vector<ll>(V,0));
    cost.assign(V,vector<ll>(V,INF));

    rep(i,0,E){
        cin >> u >> v >> c >> d;
        capacity[u][v] = c;
        cost[u][v] = d;
    }
    cout << min_cost_ssp(0,V-1,F) << endl;
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