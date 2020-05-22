#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)
const ll INF = 1LL << 50;


//https://atcoder.jp/contests/abc061/tasks/abc061_d
vector<ll> dist,pred,u,v,w;
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
    ll n,m;// Node num, Edge num, start point ,goal point
    cin >> n >> m ;

    u.assign(m,0);
    v.assign(m,0);
    w.assign(m,0);
    dist.assign(n,INF);
    pred.assign(n,-1);
    negative.assign(n,false);

    for(ll i=0;i<m;i++)cin >>u[i] >>v[i] >>w[i];
    transform(u.begin(),u.end(),u.begin(),[](ll x){return x-1;});
    transform(v.begin(),v.end(),v.begin(),[](ll x){return x-1;});
    transform(w.begin(),w.end(),w.begin(),[](ll x){return -x;});
    bellman_ford(n,0);
    ll ans = dist[n-1]*(-1);
    negative_check(n);
    if(negative[n-1]) cout << "inf"<< endl;
    else cout << ans << endl;
}