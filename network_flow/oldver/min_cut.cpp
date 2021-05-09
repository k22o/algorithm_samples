#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)
using ipair = pair<ll,ll>;

//https://atcoder.jp/contests/abc010/tasks/abc010_4

vector<vector<ll>> capacity;
vector<vector<ll>> flow;
vector<ll> pred;

//増加させることができる経路を探す
//可能経路は，predに保存される ex. pred[v] = u ... u->vの経路
bool findPath(ll s, ll t){
    ll N = capacity.size();
    pred.assign(N,-1);
    
    //幅優先探索
    queue<ll> que; que.push(s);
    while(!que.empty()){
        ll u = que.front(); que.pop(); 

        //Flowネットワークを調べる
        for(ll v=0;v<N;v++){
            //「経路がある」「先の点が未探索」「増加可能」
            if(capacity[u][v]>0 && pred[v]==-1 && capacity[u][v]>flow[u][v]){
                pred[v] = u;
                if (v== t) return true;
                que.push(v);
            }
        }
        //残余ネットワークを調べる
        for(ll v=0;v<N;v++){
            if(capacity[v][u]>0 && pred[v]==-1 && flow[v][u]>0){
                pred[v] = u;
                que.push(v);
            }
        }
    }
    return false;
}

//ネットワークを更新する．
void update(ll s, ll t){
    ll tmp,u,v,delta = INF;//増加分

    //最小の増加量をtargetから遡って探す
    v = t;
    while(v!=s){
        u = pred[v];
        if(capacity[u][v]>0) tmp = capacity[u][v] -flow[u][v];
        else if (capacity[v][u]>0) tmp = flow[v][u];
        delta = min(delta,tmp);
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
}

ll edmonds_karp(ll s, ll t){    
    //増加経路を探索し，見つかったら更新する
    while(1){
        if(findPath(s,t)==false) break;
        else update(s,t);
    }
    ll ans = 0;
    for(ll v=0;v<capacity.size();v++) ans += flow[s][v];
    return ans;
}

int main(){
    ll N,G,E,u,v;
    cin >> N >> G >> E;
    capacity.assign(N+1,vector<ll>(N+1,0));
    flow.assign(N+1,vector<ll>(N+1,0));

    vector<ll> p(G);

    rep(i,0,G) cin >> p[i];
    rep(i,0,E){
        cin >> u >> v ;
        if(u==0) capacity[u][v] = 1;
        else if (v==0) capacity[v][u] = 1;
        else {capacity[u][v] = 1; capacity[v][u] = 1;}
    }
    rep(i,0,G){
        capacity[p[i]][N] = 1;        
    }
    cout << min(edmonds_karp(0,N),G) << endl;
}
