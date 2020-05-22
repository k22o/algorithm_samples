#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 1000000000000000LL
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)
using ipair = std::pair<ll,ll>;

const ll MAX = 5000;
const ll MOD = (ll)1e9+7;

// aとMODが互いの素なら使える
ll fac[MAX],finv[MAX],inv[MAX];
void comb_init(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;//(1/(n!))のinv
    inv[1] =1; // (1/n)のinv
    for(ll i=2;i<MAX;i++){
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
    }    
}
ll comb_MOD(ll n, ll k){ //nCk%MOD
    if(n<k||n<0||k<0) return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}
ll pow_MOD(ll a, ll n){//pow(a,b)%MOD
    ll res=1;
    while(n>0){
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

//bell数の直接計算
ll bell_num(ll n, ll k){
    comb_init();
    vector<ll> sum_tmp(k+1,0);
    sum_tmp[0] = 1;
    rep(j,1,k+1){
        if(j%2==0)sum_tmp[j] = (sum_tmp[j-1]+finv[j])%MOD;
        else sum_tmp[j] = (sum_tmp[j-1]-finv[j])%MOD;
        if (sum_tmp[j]<0) sum_tmp[j] += MOD;        
    }
    ll ans =0;
    rep(i,0,k+1){
        ans = (ans + (pow_MOD(i,n) *finv[i])%MOD * sum_tmp[k-i] %MOD)%MOD;
    }
    return ans;
}


int main(){
    ll n,k;
    cin >> n >> k;
    cout << bell_num(n,k) << endl;
}