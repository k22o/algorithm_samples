#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)

const ll MOD = (ll)1e9+7;

//https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
ll add_MOD(ll a, ll b){
    return ((a%MOD) + (b%MOD))%MOD;
}

//負の数にも対応させたMOD
ll mod(ll val, ll m) {
  ll res = val % m;
  if (res < 0) res += m;
  return res;
}

ll sub_MOD(ll a, ll b){
    //return (a - b)%MOD;
    return mod((a%MOD) -(b%MOD),MOD);
}
ll mul_MOD(ll a, ll b){
    return ((a%MOD) * (b%MOD))%MOD;
}

// aとMODが互いの素なら使える
// 逆元に対するMODの結果
ll inv_MOD(ll a){
    ll b=MOD, u=1,v=0;
    while(b){
        ll t = a/b;
        a -= t*b;swap(a,b);
        u -= t*v;swap(u,v);
    }
    u %= MOD;
    if(u<0) u+=MOD;
    return u;
}

ll div_MOD(ll a,ll b){
    return (a%MOD) * inv_MOD(b) %MOD;
}

ll pow_MOD(ll a, ll n){//pow(a,b)%MOD
    ll res=1;
    while(n>0){
        //nと1のAND計算
        //nの1桁目が1なら計算する
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        //右にビットシフトして桁を1つ落とす
        n >>= 1;
    }
    return res;
}

int main(){
    ll a,b;
    cin >> a >> b;
    cout << pow_MOD(a,b) << endl;
}