#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)

//https://atcoder.jp/contests/arc090/tasks/arc090_b
struct Edge {
    int pre,post,weight;
    bool operator<(const Edge& o) const{
        return weight < o.weight;
    }
};

class UnionFind{
    private:
        vector<int> par;
        vector<int> rank;
        vector<int> diff_weight;
    public:
        UnionFind(int N):par(N),rank(N),diff_weight(N){
            for(int i=0;i<N;i++){
                this->par[i] = i;
                this->rank[i] = 0;
                this->diff_weight[i] =0;
            }
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

    void unite(int x_ch, int y_ch, int w){
        w = w + this->weight(x_ch) - this->weight(y_ch);
        int x = this->root(x_ch);
        int y = this->root(y_ch);
        if(x != y){

            if(this->rank[x]<this->rank[y]){swap(x,y);w=-w;}
            if(this->rank[x]=this->rank[y]) this->rank[x] ++;
            this->par[y] = x;
            this->diff_weight[y] = w;
            }
    };

    int diff(int x,int y){
        return this->weight(y)-this->weight(x);
    }
};

int main(){
    int N,M,L,R,D;
    cin >> N >> M;
    UnionFind tree(N);
    vector<Edge>edge_arr;
    for(int i=0;i<M;i++){
        cin>>L >>R >> D;
        Edge tmp{L-1,R-1,D};
        edge_arr.push_back(tmp);
    }

    for(int i=0;i<M;i++){
        int pre = edge_arr[i].pre;
        int post = edge_arr[i].post;
        if(tree.root(pre) == tree.root(post)){
            int diff = tree.diff(pre,post);
            if(diff!=edge_arr[i].weight){
                cout << "No" << endl;
                return 0;
            }
        }
        else tree.unite(pre, post,edge_arr[i].weight);
    }
    cout << "Yes" << endl;
}
