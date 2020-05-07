#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)
const ll INF = 1LL << 50;

//https://atcoder.jp/contests/abc061/tasks/abc061_d
vector<ll> bellman_ford(ll V,ll start, vector<ll>u, vector<ll>v, vector<ll>w){
    /*
    最短経路問題 負もOK
    V: node_num 0~(v-1)
    u,v,w : u-> weight(w) ->v
    */
    vector<ll>dist(V,INF);
    vector<ll> pred(V,-1);
    dist[start] = 0;

    for(ll i=0;i<V;i++){
        for(ll j=0;j<u.size();j++){
            if (dist[u[j]] == INF) continue;
            if (dist[u[j]]+w[j] < dist[v[j]]){
                dist[v[j]] = dist[u[j]]+w[j];
                pred[v[j]] = u[j];
            }
        }
    }
    return dist;
}

//負の経路の検出
vector<bool> negative_check(ll V, vector<ll> u, vector<ll> v, vector<ll> w,vector<ll> dist){
    vector<bool> negative(V,false);
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
    return negative;
}


int main(){
    ll n,m;// Node num, Edge num, start point ,goal point
    cin >> n >> m ;
    vector<ll>u(m),v(m),w(m);// u -> w -> v
    for(ll i=0;i<m;i++)cin >>u[i] >>v[i] >>w[i];
    transform(u.begin(),u.end(),u.begin(),[](ll x){return x-1;});
    transform(v.begin(),v.end(),v.begin(),[](ll x){return x-1;});
    transform(w.begin(),w.end(),w.begin(),[](ll x){return -x;});
    vector<ll> dist = bellman_ford(n,0,u,v,w);
    ll ans = dist[n-1]*(-1);
    vector<bool> negative = negative_check(n,u,v,w,dist);
    //for(auto x :dist) cout << x << endl;
    if(negative[n-1]) cout << "inf"<< endl;
    else cout << ans << endl;
}