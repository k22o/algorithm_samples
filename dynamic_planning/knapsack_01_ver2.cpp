#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)

//https://atcoder.jp/contests/abc015/tasks/abc015_4
int main(){
    int W,N,K;
    cin >> W >> N >> K;
    vector<int> A(N,0),B(N,0);
    rep(i,0,N) cin >>A[i] >> B[i];
    ll dp[N+1][W+1][K+1];
    fill((ll*)dp, (ll*)dp + sizeof(dp)/sizeof(ll),0);
    rep(i,1,N+1){
        rep(j,1,W+1){
            rep(k,1,K+1){
                if(j-A[i-1]>=0) dp[i][j][k] = max(dp[i-1][j][k],dp[i-1][j-A[i-1]][k-1]+B[i-1]);
                else dp[i][j][k] = dp[i-1][j][k];
            }
        }
    }

    int ans = 0;
    rep(i,0,W+1)rep(k,0,K+1)if(dp[N][i][k] > ans) ans = dp[N][i][k];
    cout << ans << endl;
}
