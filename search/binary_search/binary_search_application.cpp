#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using itpl = tuple<ll,ll>;

//https://atcoder.jp/contests/abc077/tasks/arc084_a
int main(){
    ll N;
    cin >> N;
    vector<ll>A(N,0),B(N,0),C(N,0);
    rep(i,0,N) cin >> A[i];
    rep(i,0,N) cin >> B[i];
    rep(i,0,N) cin >> C[i];
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());
    
    vector<ll> BCcounts(N,0);
    for(ll i=N-1;i>=0;i--){
        auto itr = lower_bound(C.begin(),C.end(),B[i]+1);
        BCcounts[i] = distance(itr,C.end());
        if(i!=N-1) BCcounts[i] += BCcounts[i+1];
    }

    ll ans = 0;
    for(ll i=0;i<N;i++){
        auto itr = lower_bound(B.begin(),B.end(),A[i]+1);
        if(itr == B.end()) break;
        ans += BCcounts[distance(B.begin(),itr)];
    }
    cout << ans << endl;
}
