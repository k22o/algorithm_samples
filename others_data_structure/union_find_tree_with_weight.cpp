#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)

//https://atcoder.jp/contests/arc090/tasks/arc090_b
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
        vector<int> diff_weight;
    public:
        UnionFind(int _N){
            this->N=_N;
            for(int i=0;i<this->N;i++) this->par.push_back(i);
            for(int i=0;i<this->N;i++) this->rank.push_back(0);
            for(int i=0;i<this->N;i++) this->diff_weight.push_back(0);
        };//constructer
    ~UnionFind(){};
    int root(int x){
        if(x==this->par[x]) return x;
        else{
            this->diff_weight[x] += this->diff_weight[par[x]];
            return root(this->par[x]);
        }
    };

    int weight(int x){
        this->root(x);
        return this->diff_weight[x];
    }

    void unite(int x, int y, int w){
        w = w + this->weight(x) - this->weight(y);
        int x_par = this->root(x);
        int y_par = this->root(y);
        if(x_par != y_par){
            if(this->rank[x_par]<this->rank[y_par]){swap(x_par,y_par);w=-w;}
            if(this->rank[x_par]=this->rank[y_par]) this->rank[x_par] ++;
            this->par[y_par] = x_par;
            this->diff_weight[y_par] = w;
            }
    };

    int diff(int x,int y){
        return this->weight(y)-this->weight(x);
    }
};

int main(){
    int N,M;
    cin >> N >> M;
    vector<int>L(M),R(M),D(M);
    for(int i=0;i<M;i++) cin>>L[i]>>R[i] >> D[i];
    transform(L.begin(),L.end(),L.begin(),[](int i){return i-1;});
    transform(R.begin(),R.end(),R.begin(),[](int i){return i-1;});
    UnionFind tree(N);
    vector<Edge>edge_arr;

    for(int i=0;i<M;i++){
        Edge tmp(L[i],R[i],D[i]);
        edge_arr.push_back(tmp);
        }    
    for(int i=0;i<M;i++){
        int pre = edge_arr[i].get_pre();
        int post = edge_arr[i].get_post();
        if(tree.root(pre) == tree.root(post)){
            int diff = tree.diff(pre,post);
            if(diff!=edge_arr[i].get_weight()){
                cout << "No" << endl;
                return 0;
            }
        }
        else tree.unite(pre, post,edge_arr[i].get_weight());
    }
    cout << "Yes" << endl;
}
