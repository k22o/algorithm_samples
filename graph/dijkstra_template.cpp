#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ipair = std::pair<int,int>;


vector<int> dijkstra(int V,int start, vector<int>u, vector<int>v, vector<int>w){
    /*
    最短経路問題
    V: node_num 0~(v-1)
    u,v,w : u-> weight(w) ->v
    */
    vector<int>dist(V,INF),pred(V,INF);
    dist[start] = 0;

    priority_queue<ipair,vector<ipair>,greater<ipair>> que;
    for(int i=0;i<V;i++) que.push(make_pair(dist[i],i));

    while(!que.empty()){
        ipair top = que.top();
        que.pop();
        //cout << "top " << top.first << " idx "<<top.second << endl;        
        for(int i=0;i<u.size();i++){
            if(u[i]==top.second && dist[v[i]]>dist[u[i]]+w[i]){
                dist[v[i]] = dist[u[i]] + w[i];
                pred[v[i]] = u[i];
                que.push(make_pair(dist[u[i]] + w[i],v[i])); 
        }
        }
    }
    return dist;
}

int main(){
    int n,m,s,t;// Node num, Edge num, start point ,goal point
    cin >> n >> m >> s>> t;
    vector<int>u(m),v(m),w(m);// u -> w -> v
    for(int i=0;i<m;i++)cin >>u[i] >>v[i] >>w[i];
    //transform(u.begin(),u.end(),u.begin(),[](int i){return i-1;});
    //transform(v.begin(),v.end(),v.begin(),[](int i){return i-1;});
    rep(i,0,m){
        u.push_back(v[i]);
        v.push_back(u[i]);
        w.push_back(w[i]);
    }
    vector<int>dist = dijkstra(n,s,u,v,w);
    for(auto x :dist) cout << x << endl;
}