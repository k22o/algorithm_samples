#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000000
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)


//INDEXは1始まり
class binIdxTree{
    private:
        vector<ll> tree;
        ll N;

    public:
       binIdxTree(ll n, ll init_num= 0){
           this-> N = n;
           this->tree.assign(n+1,init_num);
        };
    ~binIdxTree(){};

    // Idx a に wを加算
    void add(ll a, ll w){
        for(ll x=a;x<=this->N; x+= x& -x) this->tree[x] +=w;

    };
    //Idx:1からIdx:aまでの和を計算
    ll sum(ll a){
        ll ret = 0;
        for(ll x=a;x>0;x-=x&-x) ret += this->tree[x];
        return ret;
    };
};

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,0,N) cin >> A[i];

    binIdxTree tree(N);
    ll ans = 0;
    rep(i,0,N){
        ans += i - tree.sum(A[i]);
        tree.add(A[i],1);
    }
    cout << ans << endl;
}