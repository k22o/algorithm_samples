#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)


//Wが大きすぎるときは，メモリ削減のため，
//DPの値をWを最小化する観点で考える．
//https://atcoder.jp/contests/abc032/tasks/abc032_d
int main(){
    int N,W;
    cin >> N >> W;
    vector<int> v(N,0),w(N,0);
    rep(i,0,N) cin >>v[i] >> w[i];
    int xMax = *max_element(v.begin(),v.end())*N+1;
    int dp[N+1][xMax];
    fill((ll*)dp, (ll*)dp + sizeof(dp)/sizeof(ll),INF);
    dp[0][0] = 0;

    rep(i,1,N+1){
        rep(j,1,xMax){
            cout << i << " " << j << endl;
            if(j-v[i-1]>=0) dp[i][j] = min(dp[i-1][j],dp[i-1][j-v[i-1]]+w[i-1]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    /*
    rep(i,0,N+1){
        rep(j,0,xMax) cout << dp[i][j] << " ";
        cout << endl;
    }*/

    int ans = 0;
    int wMin = INF;
    rep(i,0,xMax){
        if( i > ans && dp[N][i] < wMin && dp[N][i]!=0){
            ans = i;
            wMin = dp[N][i];
        }
    }
    cout << ans << endl;
}
