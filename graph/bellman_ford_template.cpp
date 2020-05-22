#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)
const ll INF = 1LL << 50;

//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=jp
vector<ll> u,v,w,dist,pred;
void bellman_ford(ll V,ll start){
    /*
    最短経路問題 負もOK
    V: node_num 0~(v-1)
    u,v,w : u-> weight(w) ->v
    */
    dist[start] = 0;
    pred[start] = -1;

    for(ll i=0;i<V;i++){
        for(ll j=0;j<u.size();j++){
            if (dist[u[j]] == INF) continue;
            if (dist[u[j]]+w[j] < dist[v[j]]){
                dist[v[j]] = dist[u[j]]+w[j];
                pred[v[j]] = u[j];
            }
        }
    }
}

//負の経路の検出
vector<bool> negative;
void negative_check(ll V){
    for(ll i=0;i<V;i++){
        for(ll j=0;j<u.size();j++){
            if(dist[u[j]]==INF) continue;
            if (dist[u[j]]+w[j] < dist[v[j]]){
                dist[v[j]] = dist[u[j]]+w[j];
                negative[v[j]] = true;
            }
            if(negative[u[j]]) negative[v[j]]=true;
        }
    }
}

int main(){
    ll n,m,s;// Node num, Edge num, start point ,goal point
    cin >> n >> m >> s;
    u.assign(m,0);
    v.assign(m,0);
    w.assign(m,0);
    dist.assign(n,INF);
    pred.assign(n,-1);
    negative.assign(n,false);

    for(ll i=0;i<m;i++)cin >>u[i] >>v[i] >>w[i];
    //transform(u.begin(),u.end(),u.begin(),[](ll i){return i-1;});
    //transform(v.begin(),v.end(),v.begin(),[](ll i){return i-1;});
    //rep(i,0,m){u.push_back(v[i]); v.push_back(u[i]);}#無向グラフなら
    
    bellman_ford(n,s);
    negative_check(n);
    
    if(find(negative.begin(),negative.end(),true)!=negative.end()) cout << "NEGATIVE CYCLE" << endl;
    else{
        for(auto x:dist) cout << x << endl;
    }
}