#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)


//http://poj.org/problem?id=1182
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
        if(x==y) return; 

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
        return this->root(x) == this->root(y);
    };
};


int main(){

    int N,k,x,y,t,ans = 0;
    cin >> N >> k;
    UnionFind tree(3*N);

    for(int i=0;i<k;i++){
        cin >> t >> x >> y;
        x--;
        y--;
        cout << ans << endl;
        if(x<0 || x>=N || y<0 || y>=N) {
            ans++;
            continue;
        }
        if(t==1) {
            if(tree.isEqualRoot(x,y+N) || tree.isEqualRoot(x,y+2*N)) ans ++;
            else{
                tree.unite(x,y);
                tree.unite(x+N,y+N);
                tree.unite(x+2*N,y+2*N);
            }
        }
        else if(t==2) {
            if(tree.isEqualRoot(x,y)||tree.isEqualRoot(x,y+2*N)) ans++;
            else{
                tree.unite(x,y+N);
                tree.unite(x+N,y+2*N);
                tree.unite(x+2*N,y);
            }
        }
    }    
    cout << ans << endl;
}
