#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)
using itpl = tuple<ll,ll,ll>;

//GCDの繰り返しに同じ
ll euclidean(ll a, ll b){
    if(b==0) return a;
    return euclidean(b,a%b);
}

// a,bの最大公約数を求める
// ax + by = gcd(a,b)を解くこと
itpl extended_euclidean(ll a,ll b){
    int d,x,y;
    if(b==0){
        x=1;
        y=0;
        return itpl(make_tuple(a,1,0));
    }
    tie (d,y,x) = extended_euclidean(b,a%b);
    return make_tuple(d,x,y-a/b*x);
}

int main(){
    ll x,y,d;
    tie(d,x,y) = extended_euclidean(110,29);
    cout << x << " " << y << " " << d << endl;
}