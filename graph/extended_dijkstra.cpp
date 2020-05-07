#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using itpl = std::tuple<int,int,int>;

//https://atcoder.jp/contests/abc164/tasks/abc164_e
vector<vector<int>> dijkstra(int V,int start, vector<int>u, vector<int>v, vector<int>a,vector<int>b, int direct_flag,int S){
    /*
    最短経路問題
    V: node_num 0~(v-1)
    u,v,w : u-> weight(w) ->v
    */
    int coinMax = (V-1)*(*max_element(a.begin(),a.end()));
    vector<vector<int>>dist(V,vector<int>(coinMax+1,INF));
    vector<vector<int>>pred(V,vector<int>(coinMax+1,INF));
    dist[start][S] = 0;

    priority_queue<itpl,vector<itpl>,greater<itpl>> que;
    rep(i,0,V){rep(j,0,coinMax+1) que.push(make_tuple(dist[i][j],i,j));}

    while(!que.empty()){
        itpl top = que.top();
        que.pop();
        
        for(int i=0;i<u.size();i++){
            for(int direct=0;direct<direct_flag;direct++){
                vector<int> pre,post;
                if(direct==0){
                    pre = u;
                    post = v;
                } 
                else{
                    pre = v;
                    post = u;
                } 
                if(direct==1 && pre[i]==post[i]) continue;
                if(pre[i]==get<1>(top) && get<2>(top)-a[i]>=0 && dist[post[i]][get<2>(top)-a[i]]>dist[pre[i]][get<2>(top)]+b[i]){
                    //cout << get<0>(top) <<" "<< get<1>(top) <<" " << get<2>(top) <<endl;
                    int tmp = (get<2>(top)-a[i]) > coinMax ? coinMax : get<2>(top)-a[i];
                    dist[post[i]][tmp] = dist[pre[i]][get<2>(top)] + b[i];
                    pred[post[i]][tmp] = pre[i];
                    que.push(make_tuple(dist[pre[i]][get<2>(top)] + b[i] ,post[i],tmp)); 
                }
            }
        }
    }
    return dist;
}

int main(){
    int n,m,s,t;// Node num, Edge num, start point ,goal point
    cin >> n >> m >> s;
    vector<int>u(m),v(m),a(m),b(m),c(n),d(n);// u -> w -> v
    rep(i,0,m)cin >>u[i] >>v[i] >>a[i]>>b[i];
    transform(u.begin(),u.end(),u.begin(),[](int i){return i-1;});
    transform(v.begin(),v.end(),v.begin(),[](int i){return i-1;});
    rep(i,0,n)cin >>c[i] >>d[i];
    rep(i,0,n){ 
        u.push_back(i);
        v.push_back(i);
        a.push_back(-c[i]);
        b.push_back(d[i]);
    }
    int direct_flag = 2;
    vector<vector<int>>dist = dijkstra(n,0,u,v,a,b,direct_flag,s);
    /*rep(i,0,n){
        rep(j,0,dist[0].size()) cout << dist[i][j] << " ";
        cout << endl;
    }*/

    rep(i,1,n){
        int ans = INF;
        rep(j,0,dist[0].size()){if(ans>dist[i][j]) ans = dist[i][j];}
        cout << ans << endl;
    }

}