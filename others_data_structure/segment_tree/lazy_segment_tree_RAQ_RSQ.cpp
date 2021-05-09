#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000000
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)


//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&lang=jp
class LazySegmentTree{
    private:
        vector<ll> tree,lazy;//tree:値 lazy:遅延木
        ll last_node;//最終層のノード数

    public:
        LazySegmentTree(ll n, ll init_tree= 0 ,ll init_lazy= 0){
            this-> last_node = 1;
            while(this->last_node< n) this->last_node *=2;//最後の子ノードの数
            this->tree.assign((this->last_node*2-1),init_tree);
            this->lazy.assign((this->last_node*2-1),init_lazy);
        };

    // ノードkに対し，遅延配列から値を伝搬する
    void eval(ll k, ll l, ll r){
        if(this->lazy[k] !=0){
            this->tree[k] += this->lazy[k];
            if(r-l>1){
                this->lazy[2*k+1] += this->lazy[k]/2;
                this->lazy[2*k+2] += this->lazy[k]/2;
            }
            this->lazy[k]=0;
        }
    };
    
    // aからbまでのノードにwを加算する
    void add(ll a, ll b, ll w, ll k=0,ll l=0, ll r=-1){
        if (r<0) r= this-> last_node;
        eval(k,l,r);
        //範囲外なら何もしない
        if(b<=l||a>=r) return;
        //1つのセグメントにすっぽり
        if(a<=l && r<=b){
            this->lazy[k] += (r-l)*w;
            eval(k,l,r);
        }
        //そうでない
        else{
            this->add(a,b,w,2*k+1,l,(l+r)/2);
            this->add(a,b,w,2*k+2,(l+r)/2,r);
            this->tree[k] = this->tree[2*k+1] + this->tree[2*k+2];
        }
    };

    //範囲は[a,b)
    ll getSum(ll a, ll b, ll k=0, ll l=0, ll r=-1){
        if(r<0) r=this-> last_node;
        eval(k,l,r);
        if(b<=l||a>=r) return 0;
        if(a<=l && r<=b) return this->tree[k];
        else{
            ll tmp1 = this->getSum(a,b,2*k+1,l,(l+r)/2);
            ll tmp2 = this->getSum(a,b,2*k+2,(l+r)/2,r);
            return tmp1+tmp2;
        }
    };
};

int main(){
    ll n,q,query,s,t,x;
    cin >> n >> q;
    LazySegmentTree tree(n);
    vector<ll> ans = {};
    rep(i,0,q){
        cin >> query;
        if(query==0){
            cin >> s >> t >> x;
            tree.add(s-1,t,x);
        }else{
            cin >> s >> t;
            ans.push_back(tree.getSum(s-1,t));
        }
    }
    for(ll tmp: ans) cout << tmp << endl;
}
