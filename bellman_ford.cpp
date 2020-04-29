#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<cmath>
using namespace std;
#define INF 100000000

//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=jp
vector<int> bellman_ford(int V,int start, vector<int>u, vector<int>v, vector<int>w, int direct_flag){
    /*
    最短経路問題 負もOK
    V: node_num 0~(v-1)
    u,v,w : u-> weight(w) ->v
    */
    vector<int>dist(V,INF),pred(V);
    dist[start] = 0;

    int newLen;
    for(int i=1;i<=V;i++){
        bool failOnUpdate = (i==V);

        for(int j=0;j<u.size();j++){
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

                newLen = dist[pre[j]]+w[j];
                if (newLen < dist[post[j]]){
                    if(failOnUpdate){
                        cout << "can't apply this algorithm" << endl;
                    }
                    dist[post[j]] = newLen;
                    pred[post[j]] = pre[j];
                }
            }
        }
    }
    return dist;
}

int main(){
    int n,m,s;// Node num, Edge num, start point ,goal point
    cin >> n >> m >> s;
    vector<int>u(m),v(m),w(m);// u -> w -> v
    for(int i=0;i<m;i++)cin >>u[i] >>v[i] >>w[i];
    vector<int> dist;
    int direct_flag = 1;//1:単方向 2:双方向
    //transform(u.begin(),u.end(),u.begin(),[](int i){return i-1;});
    //transform(v.begin(),v.end(),v.begin(),[](int i){return i-1;});
    dist = bellman_ford(n,s,u,v,w,direct_flag);
    for(auto x :dist) cout << x << endl;
}