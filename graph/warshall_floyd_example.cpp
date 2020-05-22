#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define rep(i,a,b) for(ll(i)=a;(i)<(ll)(b);(i)++)
#define INF 100000000


//https://atcoder.jp/contests/abc073/tasks/abc073_d
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
    ll n,m,R,tmpu,tmpv,tmpw;// Node num, Edge num
    cin >> n >> m >> R;

    dist.assign(n,vector<ll>(n,INF));
    u.assign(2*m,0);
    v.assign(2*m,0);
    w.assign(2*m,0);

    vector<ll>r(R);
    rep(i,0,R) cin >> r[i];
    transform(r.begin(),r.end(),r.begin(),[](ll i){return i-1;});
    sort(r.begin(), r.end());

    rep(i,0,m){
        cin >> tmpu >> tmpv >> tmpw;
        u[i] = tmpu -1;
        v[i] = tmpv -1;
        w[i] = tmpw;
        u[i+m] = tmpv -1;
        v[i+m] = tmpu -1;
        w[i+m] = tmpw;
    }

    warshall_floyd(n);
    /*
    cout << "---------------" << endl;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cout << dist[i][j] << " ";
        }    
        cout << endl;
    }*/
    
    ll ans = INF;
    do{
        ll tmp = 0;
        for(ll i=0;i<r.size()-1;i++) tmp += dist[r[i]][r[i+1]];
        if(tmp<ans) ans = tmp;
    }while(next_permutation(r.begin(),r.end()));

    cout << ans << endl;
}