#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
#define INF 100000000


vector<vector<ll>> warshall_floyd(int V, vector<int>u, vector<int>v, vector<ll>w, int direct_flag){
    /*
    全経路での最短経路問題
    V: node_num 0~(v-1)
    u,v,w : u-> weight(w) ->v
    */
    vector<vector<ll>> dist(V,vector<ll>(V,INF));
    //pred(V);
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
    int n,m;// Node num, Edge num
    cin >> n >> m;
    vector<int>u(m),v(m);
    vector<ll>w(m);// u -> w -> v
    for(int i=0;i<m;i++)cin >>u[i] >>v[i] >>w[i];
    vector<vector<ll>> dist;
    int direct_flag = 1;//1:単方向 2:双方向
    //transform(u.begin(),u.end(),u.begin(),[](int i){return i-1;});
    //transform(v.begin(),v.end(),v.begin(),[](int i){return i-1;});
    dist = warshall_floyd(n,u,v,w,direct_flag);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << dist[i][j] << " ";
        }    
        cout << endl;
    }
}