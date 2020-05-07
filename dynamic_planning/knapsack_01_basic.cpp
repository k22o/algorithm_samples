#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)

//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B&lang=jp
int main(){
    int N,W;
    cin >> N >> W;
    vector<int> v(N,0),w(N,0);
    rep(i,0,N) cin >>v[i] >> w[i];
    vector<vector<int>> dp(N+1,vector<int>(W+1,0));
    rep(i,1,N+1){
        rep(j,1,W+1){
            if(j-w[i-1]>=0) dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    
    rep(i,0,N+1){
        rep(j,0,W+1) cout << dp[i][j] << " ";
        cout << endl;
    }

    int ans = 0;
    rep(i,0,W+1) if(dp[N][i] > ans) ans = dp[N][i];
    cout << ans << endl;
}
