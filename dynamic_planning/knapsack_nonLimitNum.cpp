#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)

//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_C&lang=jp
int main(){
    int N,W;
    cin >> N >> W;
    vector<ll> v(N,0),w(N,0);
    rep(i,0,N) cin >>v[i] >> w[i];   
    ll dp[N+1][W+1];
    fill((ll*)dp, (ll*)dp + sizeof(dp)/sizeof(ll),0);
    rep(i,1,N+1){
        rep(j,0,W+1){
            //個数制限がないときは，dp[i]に追加していく形
            if(j-w[i-1]>=0) dp[i][j] = max(dp[i-1][j],dp[i][j-w[i-1]]+v[i-1]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    
    rep(i,0,N+1){
        rep(j,0,W+1) cout << dp[i][j] << " ";
        cout << endl;
    }

    ll ans = 0;
    rep(i,0,N+1)rep(j,0,W+1) if(dp[i][j] > ans) ans = dp[i][j];
    cout << ans << endl;
}
