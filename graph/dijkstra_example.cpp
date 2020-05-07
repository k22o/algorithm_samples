#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 1000000000000000LL
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ipair = std::pair<ll,ll>;

//https://atcoder.jp/contests/soundhound2018-summer-qual/tasks/soundhound2018_summer_qual_d
vector<ll> dijkstra(int V,int start, vector<ll>u, vector<ll>v, vector<ll>w){
    /*
    最短経路問題
    V: node_num 0~(v-1)
    u,v,w : u-> weight(w) ->v
    */
    vector<ll>dist(V,1e15),pred(V);
    dist[start] = 0;

    priority_queue<ipair,vector<ipair>,greater<ipair>> que;
    for(int i=0;i<V;i++) que.push(make_pair(dist[i],(ll)i));

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
    vector<ll>u(m),v(m),a(m),b(m);// u -> w -> v
    for(int i=0;i<m;i++)cin >>u[i] >>v[i] >>a[i] >>b[i];
    ll money = 1e15;
    transform(u.begin(),u.end(),u.begin(),[](int i){return i-1;});
    transform(v.begin(),v.end(),v.begin(),[](int i){return i-1;});
    rep(i,0,m){
        u.push_back(v[i]);
        v.push_back(u[i]);
        a.push_back(a[i]);
        b.push_back(b[i]);
    }
    vector<ll> dist1 = dijkstra(n,s-1,u,v,a);
    vector<ll> dist2 = dijkstra(n,t-1,u,v,b);
    vector<ll> sumDist(n);
    rep(i,0,n) sumDist[i] = dist1[i]+dist2[i];
    for(int i=0;i<n;i++){
        cout << money - *min_element(sumDist.begin()+i,sumDist.end())<< endl;
    }

}