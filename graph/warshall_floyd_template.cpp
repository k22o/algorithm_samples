#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)
#define INF 100000000

vector<ll> u,v,w;
vector<vector<ll>> dist;
void warshall_floyd(ll V){
    /*
    全経路での最短経路問題
    V: node_num 0~(v-1)
    u,v,w : u-> weight(w) ->v
    */
    for(ll i=0;i<V;i++) dist[i][i] = 0;
    for(ll i=0;i<u.size();i++){
        dist[u[i]][v[i]] = w[i];       
    }
    for(ll k=0;k<V;k++){
        for(ll i=0;i<V;i++){
            for( ll j=0;j<V;j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }  
}

int main(){
    ll n,m;// Node num, Edge num
    cin >> n >> m;
    dist.assign(n,vector<ll>(n,INF));
    //無向グラフなら，2*mにして！
    u.assign(m,0);
    v.assign(m,0);
    w.assign(m,0);

    for(ll i=0;i<m;i++)cin >>u[i] >>v[i] >>w[i];
    transform(u.begin(),u.end(),u.begin(),[](ll x){return x-1;});
    transform(v.begin(),v.end(),v.begin(),[](ll x){return x-1;});
    warshall_floyd(n);
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cout << dist[i][j] << " ";
        }    
        cout << endl;
    }
}