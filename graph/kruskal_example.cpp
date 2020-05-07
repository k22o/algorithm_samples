#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)

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
    ll n,m,tmp1,tmp2;
    cin >> n;
    vector<pair<ll,ll>> x(n),y(n);
    for(ll i=0;i<n;i++) {
        cin >>tmp1 >>tmp2;
        x[i] = make_pair(tmp1,i);
        y[i] = make_pair(tmp2,i);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    vector<Edge> E((n-1)*2);
    for(ll i=0;i<n-1;i++){
        E[2*i] = {x[i].second,x[i+1].second,x[i+1].first-x[i].first};
        E[2*i+1] = {y[i].second,y[i+1].second,y[i+1].first-y[i].first};
    }
    ll cost = kruskal(n,E);

    cout << cost << endl;
}