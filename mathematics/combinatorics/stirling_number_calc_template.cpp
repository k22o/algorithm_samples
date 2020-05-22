#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 1000000000000000LL
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)
using ipair = std::pair<ll,ll>;



ll factral(ll a){
    if(a==0||a==1) return 1;
    else return a*factral(a-1);
}

//組み合わせ
ll combination(ll n, ll k){
    int numerator=1,denominator=1;
    if (n<k) return 0;
    if (k > n-k) k=n-k;
    for(ll x=1;x<=k;x++) denominator *= x;
    for(ll x=n-k+1;x<=n;x++) numerator *= x;
    return numerator/denominator;
}

const ll MOD = (ll)1e9+7;
// aとMODが互いの素なら使える
const ll MAX = 50000;
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

ll inclusive_comb(ll n,ll k){
    ll sum = 0;
    comb_init();//MODで割る必要があるならこれも実行
    rep(i,0,k+1){
        //MODで割る必要がないならこっち
        //if((k-i)%2 == 0) sum += combination(k,i)*pow(i,n);
        //else sum -= combination(k,i)*pow(i,n);

        //MODで割る必要があるならこっち
        if((k-i)%2 == 0) sum += comb_MOD(k,i)*pow_MOD(i,n)%MOD;
        else sum -= comb_MOD(k,i)*pow_MOD(i,n)%MOD;
        if(sum<0) sum +=MOD;
    }
    return sum%MOD;
}

//stirling数を直接計算する
ll stirling_num(ll n,ll k){
    ll ans = inclusive_comb(n,k);    
    //ans = ans/(factral(k)); //MODがいらないとき
    ans = finv[k]*ans %MOD;//MODがいるとき
    return ans;
}


int main(){
    ll n,k;
    cin >> n >> k;
    cout << stirling_num(n,k) << endl;
}