#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)


//https://atcoder.jp/contests/atc001/tasks/unionfind_a
struct Edge {
    ll pre,post,weight;
    bool operator<(const Edge& o) const{
        return weight < o.weight;
    }
};


class UnionFind{
    private:
        vector<ll> par,rank;
    public:
        UnionFind(ll N):par(N),rank(N){
            for(ll i=0;i<N;i++){par[i]=i;rank[i]=0;}
        };//constructer
    ~UnionFind(){};
    ll root(ll x){
        if(x==this->par[x]) return x;
        return root(this->par[x]);
    };
    void unite(ll x_ch, ll y_ch){
        ll x = this->root(x_ch);
        ll y = this->root(y_ch);
        if(x==y) return 0; 

        if(this->rank[x]<this->rank[y]){
            this->par[x] = y;
        }
        else{
            this->par[y] = x;
            if(this->rank[x]==this->rank[y])this->rank[x]++;
        }
        /*
        ll x = this->root(x_ch);
        ll y = this->root(y_ch);
        if(x != y){
            if(this->rank[x]<this->rank[y]) this->par[x] = y;
            else this->par[y] = x;
            if(this->rank[x]==this->rank[y])this->rank[x]++;
        }
        */
    };
    bool isEqualRoot(int x, int y){
        return this->root(x) = this->root(y);
    };
};


int main(){

    int N,Q,tmp1,tmp2;
    cin >> N >> Q;
    UnionFind tree(N);
    vector<Edge>edge_arr;

    vector<int>P(Q,0);
    for(int i=0;i<Q;i++){
        cin>>P[i]>>tmp1>>tmp2;
        Edge tmp = {tmp1,tmp2,1};
        edge_arr.emplace_back(tmp);        
    }
    
    for(int i=0;i<Q;i++){
        if(P[i]==0){
            tree.unite(edge_arr[i].pre, edge_arr[i].post);
        }
        else{
            //if(tree.root(edge_arr[i].pre)==tree.root(edge_arr[i].post)) cout<<"Yes"<< endl;
            if(tree.isEqualRoot(edge_arr[i].pre,edge_arr[i].post)) cout<<"Yes"<< endl;
            else cout<<"No"<< endl;
        }        
    }    
}
