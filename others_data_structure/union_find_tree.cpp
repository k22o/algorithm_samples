#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)

//https://atcoder.jp/contests/atc001/tasks/unionfind_a
class Edge{
    private:
        int pre,post,weight;
    public:
        Edge(int _pre, int _post, int _weight){
            this->pre = _pre;
            this->post = _post;
            this->weight = _weight;
        };
        ~Edge(){};
        Edge(const Edge& o){
            this->pre = o.pre;
            this->post = o.post;
            this->weight =o.weight; 
        }; //コピーコンストラクタ

        int get_pre(){return this->pre;};
        int get_post(){return this->post;};
        int get_weight(){return this->weight;};
        bool operator<(const Edge& o) const{
            return this->weight <o.weight;
        };        
};


class UnionFind{
    private:
        int N;
        vector<int> par;
        vector<int> rank;
    public:
        UnionFind(int _N){
            this->N=_N;
            for(int i=0;i<this->N;i++) this->par.push_back(i);
            for(int i=0;i<this->N;i++) this->rank.push_back(0);
        };//constructer
    ~UnionFind(){};
    int root(int x){
        if(x==this->par[x]) return x;
        return root(this->par[x]);
    };
    void unite(int x, int y){
        int x_par = this->root(x);
        int y_par = this->root(y);
        if(x != y){
            if(x<y) swap(x,y);
            this->par[y_par] = x_par;
            if(rank[x]==rank[y])rank[x]++;
        }
    };
};


int main(){

    int N,Q;
    cin >> N >> Q;
    vector<int>P(Q,0);
    vector<int>A(Q,0);
    vector<int>B(Q,0);
    for(int i=0;i<Q;i++) cin>>P[i]>>A[i]>>B[i];
    UnionFind tree(N);
    vector<Edge>edge_arr;
    for(int i=0;i<Q;i++){
        Edge tmp(A[i],B[i],1);
        edge_arr.push_back(tmp);        
    }
    
    for(int i=0;i<Q;i++){
        if(P[i]==0){
            tree.unite(edge_arr[i].get_pre(), edge_arr[i].get_post());
        }
        else{
            if(tree.root(edge_arr[i].get_pre())==tree.root(edge_arr[i].get_post())) cout<<"Yes"<< endl;
            else cout<<"No"<< endl;
        }
        
    }
    
}
