#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)

//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp
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
        if(x != y){
            if(this->rank[x]<this->rank[y]) this->par[x] = y;
            else this->par[y] = x;
            if(this->rank[x]==this->rank[y])this->rank[x]++;
        }
    };
};

ll kruskal(ll V, vector<Edge>E){     
    //最小全域木
    //V: node_num 0~(v-1)
    //u,v,w : u-> weight(w) ->v
 
    sort(E.begin(),E.end());
    UnionFind tree(V);
    ll min_cost = 0;
    for( auto p : E){
        if(tree.root(p.pre) != tree.root(p.post)){
            min_cost += p.weight;
            tree.unite(p.pre,p.post);            
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
        Edge tmp({u[i],v[i],w[i]});
        E.push_back(tmp);
    }
    int cost = kruskal(n,E);

    cout << cost << endl;
}