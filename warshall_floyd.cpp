#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<functional>
using namespace std;
#define INF 100000000


vector<vector<long long int>> warshall_floyd(int V, vector<int>u, vector<int>v, vector<int>w, int direct_flag){
    /*
    全経路での最短経路問題
    V: node_num 0~(v-1)
    u,v,w : u-> weight(w) ->v
    */
    vector<vector<long long int>> dist(V,vector<long long int>(V,INF));
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
    vector<int>u(m),v(m),w(m);// u -> w -> v
    for(int i=0;i<m;i++)cin >>u[i] >>v[i] >>w[i];
    vector<vector<long long int>> dist;
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