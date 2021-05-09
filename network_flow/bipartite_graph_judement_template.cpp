#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ll = long long int;
using itpl = tuple<int,int,int>;

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
    int N,M;
    cin >> N >> M;
    vector<itpl> edges;
     rep(i,0,M){
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back(make_tuple(u-1,v-1,w));
        edges.push_back(make_tuple(v-1,u-1,w));
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
    bl ? cout<<"Yes":cout <<"No";
    cout << endl;

}