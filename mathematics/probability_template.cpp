#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 1000000000000000LL
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ipair = std::pair<ll,ll>;

//階乗
int factral(int a){
    if(a==0||a==1) return 1;
    else return a*factral(a-1);
}

//順列
int permutation(int n, int k){
    int ans=1;
    if (n<k) return 0;
    if (k==0) return 1;
    for(int x=n-k+1;x<=n;x++) ans *= x;
    return ans;
}

//組み合わせ
int combination(int n, int k){
    int numerator=1,denominator=1;
    if (n<k) return 0;
    if (k > n-k) k=n-k;
    for(int x=1;x<=k;x++) denominator *= x;
    for(int x=n-k+1;x<=n;x++) numerator *= x;
    return numerator/denominator;
}

//重複組み合わせ
int dup_combination(int n,int k){ //nHk
    return combination(n+k-1,k);
}

//もし階乗の結果を保存しておくなら...
//ただし，MAXは，12くらいが限界．20では無理．
const ll MAX = 11;
ll fac[MAX];

void comb_init(){
    fac[0] = 1;
    fac[1] = 1;
    for(ll i=2;i<MAX;i++){
        fac[i] = fac[i-1]*i;
    }    
}

ll comb(ll n, ll k){ 
    if(n<k) return 0;
    if(n==k||k==0) return 1;
    comb_init();
    return fac[n]/(fac[k]*fac[n-k]);
}
