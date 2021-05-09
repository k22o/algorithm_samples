#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000000
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)


class SegmentTree{
    private:
        vector<ll> tree;
        ll N;
        ll last_node;

    public:
        SegmentTree(ll n, ll init_num= INF){
            this-> N = n;
            this-> last_node = 1;
            while(this->last_node<this->N) this->last_node *=2;//最後の子ノードの数
            this->tree.assign((this->last_node*2-1),init_num);//ノードの初期化
        };

    //もとの配列のidx番目に要素について，valueで置き換え，seg木を更新する
    void segUpdate(ll idx, ll value){
        idx += (this->tree.size()-1)/2;
        this->tree[idx] = value;
        while(idx>0){
            idx = (idx-1)/2;
            this->tree[idx] = min(this->tree[idx*2+1],this->tree[idx*2+2]);
        }
    };

    //[start,fin)の区間について探索
    ll getMin(ll start, ll fin, ll k=0, ll l=0, ll r=-1){
        if(r<=start||fin<=l) return INF;
        else if (start<=l && fin>=r) return this->tree[k];
        else{
            ll c1 = this->getMin(start,fin,2*k+1,l,(l+r)/2);
            ll c2 = this->getMin(start,fin,2*k+2,(l+r)/2,r);
            return min(c1,c2);
        }
    };

    ll ret_last_node(){return this->last_node;};
    vector<ll> ret_tree(){return this->tree;};
};


int main(){
    ll n,q;
    cin >> n >> q;
    SegmentTree segTree(n);
    vector<ll> com(q,0),x(q,0),y(q,0);
    rep(i,0,q) cin >> com[i] >> x[i] >> y[i];

    rep(i,0,q){
        if(com[i]==0) segTree.segUpdate(x[i],y[i]);
        else if (com[i]==1){
            ll ans = segTree.getMin(x[i],y[i]+1,0,0,segTree.ret_last_node());
            cout << ans << endl;
        }
    }
    /*   
    vector<ll> tree = segTree.ret_tree();
    for(auto x:tree) cout << x << " ";
    cout << endl;*/
}