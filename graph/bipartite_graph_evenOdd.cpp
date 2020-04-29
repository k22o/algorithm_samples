#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ll = long long int;
using itpl = tuple<int,int,int>;


//https://atcoder.jp/contests/abc126/tasks/abc126_d
vector<int> colors(100000,0);
bool is_bipartite_graph(vector<itpl> edges, int v, int c){
    // v: node number, c: colorIndx 
    colors[v] = c;
    for(int i=0;i<edges.size();i++){
        int nextNode = get<1>(edges[i]);
        if(get<0>(edges[i]) ==v){
            if(colors[nextNode] == c) return false;
            else if(colors[nextNode] == 0 && !is_bipartite_graph(edges,nextNode,-c)) return false;
        }
    }
    return true;
}

int main(){
    //奇数長さ-重み1，直接連結
    //偶数長さ-間にノードを1つ追加，重み1とする
    //以上によって，二部グラフ判定に帰着
    int N,M,initN;
    cin >> N;
    initN = N;
    M=N;
    vector<itpl> edges;
    rep(i,0,M-1){
        int u,v,w;
        cin >> u >> v >> w;
        if(w%2==1){
            edges.push_back(make_tuple(u-1,v-1,1));
            edges.push_back(make_tuple(v-1,u-1,1));
        }
        else if(w%2==0){
            edges.push_back(make_tuple(v-1,N,1));
            edges.push_back(make_tuple(N,v-1,1));
            edges.push_back(make_tuple(u-1,N,1));
            edges.push_back(make_tuple(N,u-1,1));
            N ++;        
        }
    }
    bool bl = true;

    //非連結なグラフもあるので，色がないところを全探索
    //色は１か-1かにする
    rep(i,0,N){
        if(colors[i] == 0){
            bl = is_bipartite_graph(edges,i,1);
            if (!bl) break;
        }
    }
    if(bl){
        rep(i,0,initN){
            if(colors[i]==1) cout << '0' <<endl;
            else if(colors[i]==-1) cout << '1' <<endl;
            }
    } 
    else cout << "error"<<endl;
}