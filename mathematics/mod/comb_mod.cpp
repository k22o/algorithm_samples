#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)

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

int main(){
    ll a,b;
    cin >> a >> b;
    comb_init();
    cout << comb_MOD(a,b) << endl;
}