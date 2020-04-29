#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)

//https://atcoder.jp/contests/tdpc/tasks/tdpc_contest
int main(){
    int N;
    cin >> N;
    vector<int> p(N,0);
    rep(i,0,N) cin >>p[i];
    int maxP = accumulate(p.begin(),p.end(),0);
    vector<vector<int>> dp(N+1,vector<int>(maxP+1,0));
    rep(i,1,N+1) dp[i][0] = 1;
    rep(i,0,N)dp[i+1][p[i]] = 1;    
    rep(i,1,N+1){
        rep(j,1,maxP+1){
            if(dp[i-1][j]||dp[i][j]||(j-p[i-1]>0 && dp[i-1][j-p[i-1]])) dp[i][j]=1;
        }
    }

    rep(i,0,N+1){
        rep(j,0,maxP+1) cout << dp[i][j] << " ";
        cout << endl;
    }

    int ans = 0;
    rep(i,0,maxP+1) ans += dp[N][i];
    cout << ans << endl;
}
