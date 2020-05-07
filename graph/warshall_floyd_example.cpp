#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
#define INF 100000000

//https://atcoder.jp/contests/abc073/tasks/abc073_d
vector<vector<ll>> warshall_floyd(int V, vector<int>u, vector<int>v, vector<ll>w, int direct_flag){
    /*
    全経路での最短経路問題
    V: node_num 0~(v-1)
    u,v,w : u-> weight(w) ->v
    */
    vector<vector<ll>> dist(V,vector<ll>(V,INF));
    for(int i=0;i<V;i++) dist[i][i] = 0;
    for(int i=0;i<u.size();i++){
        dist[u[i]][v[i]] = w[i];       
        if(direct_flag==2) dist[v[i]][u[i]] = w[i];       
    }

    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for( int j=0;j<V;j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }  
    return dist;
}


int main(){
    int n,m,R;// Node num, Edge num
    cin >> n >> m >> R;
    vector<int>u(m),v(m),r(R);
    vector<ll>w(m);// u -> w -> v
    rep(i,0,R) cin >> r[i];
    sort(r.begin(), r.end());
    rep(i,0,m)cin >>u[i] >>v[i] >>w[i];
    int direct_flag = 2;//1:単方向 2:双方向
    transform(u.begin(),u.end(),u.begin(),[](int i){return i-1;});
    transform(v.begin(),v.end(),v.begin(),[](int i){return i-1;});
    transform(r.begin(),r.end(),r.begin(),[](int i){return i-1;});
    vector<vector<ll>>dist = warshall_floyd(n,u,v,w,direct_flag);
    /*
    cout << "---------------" << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << dist[i][j] << " ";
        }    
        cout << endl;
    }*/
    
    ll ans = INF;
    do{
        ll tmp = 0;
        for(int i=0;i<r.size()-1;i++) tmp += dist[r[i]][r[i+1]];
        if(tmp<ans) ans = tmp;
    }while(next_permutation(r.begin(),r.end()));

    cout << ans << endl;
}