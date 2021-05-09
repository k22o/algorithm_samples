#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)
using ipair = pair<ll,ll>;


//https://atcoder.jp/contests/abc171/tasks/abc171_e
int main(){
    ll N,tmp,total =0;
    cin >> N;
    vector<ll> a(N,0);
    vector<ll> ans(N,0);
    rep(i,0,N) cin >> a[i];
    for(int i=0;i<N;i=i+2){
        tmp = a[i] ^ a[i+1];
        total = total ^ tmp;
    }
    rep(i,0,N){
        ans[i] = total^a[i];
    }
    for(auto x:ans) cout << x << " ";
    cout << endl;
}