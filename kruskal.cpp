#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

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

    public:
        UnionFind(int _N){
            this->N=_N;
            for(int i=0;i<this->N;i++) this->par.push_back(i);
        };//constructer
    ~UnionFind(){};
    int find(int x){
        if(x==this->par[x]) return x;
        return find(this->par[x]);
    };
    void unite(int x, int y){
        int x_par = this->find(x);
        int y_par = this->find(y);
        if(x != y){ this->par[y_par] = x_par;}
    };
    void par_print(){
        for(auto x :par) cout<< x;
        cout << endl;
    };
};


int kruskal(int V, vector<Edge>E){
    
   //最小全域木
    //V: node_num 0~(v-1)
    //u,v,w : u-> weight(w) ->v
     
    sort(E.begin(),E.end());
    UnionFind tree(V);
    int min_cost = 0;
    for(int i=0;i<E.size();i++){
        int pre = E[i].get_pre();
        int post = E[i].get_post(); 
        Edge e = E[i];
        if(tree.find(pre) != tree.find(post)){
            min_cost += E[i].get_weight();
            tree.unite(pre,post);            
        }
    }
    return min_cost;
}


int main(){
    int n,m;//node num /edge num
    cin >> n >> m;
    vector<int>u(m),v(m),w(m);
    for(int i=0;i<m;i++)cin >>u[i] >>v[i] >>w[i];
    //transform(u.begin(),u.end(),u.begin(),[](int i){return i-1;});
    //transform(v.begin(),v.end(),v.begin(),[](int i){return i-1;});
    vector<Edge> E;
    for(int i=0;i<m;i++){
        Edge tmp(u[i],v[i],w[i]);
        E.push_back(tmp);
    }
    int cost = kruskal(n,E);

    cout << cost << endl;
}