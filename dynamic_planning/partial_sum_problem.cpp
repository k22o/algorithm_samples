#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)

//https://atcoder.jp/contests/maximum-cup-2018/tasks/maximum_cup_2018_d
int main(){
    int N,M,L,X;
    cin >> N >> M >> L >> X;
    vector<int> a(N,0);
    rep(i,0,N) cin >>a[i];
    vector<vector<int>> dp(N+1,vector<int>(M,INF));
    dp[0][0]=1;
    rep(i,1,N+1){
        rep(j,0,M){
            dp[i][(j+a[i-1])%M] = min(dp[i-1][j]+(j+a[i-1])/M,dp[i-1][(j+a[i-1])%M]);
        }
    }
    
    rep(i,0,N+1){
        rep(j,0,M) cout << dp[i][j] << " ";
        cout << endl;
    }

    if(dp[N][L]<X) cout << "Yes" << endl;
    else cout << "No" << endl;
}
