#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)

//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C&lang=jp
int main(){
    string X,Y;
    cin >> X >> Y;
    ll dp[X.size()+1][Y.size()+1];
    fill((ll*)dp, (ll*)dp + sizeof(dp)/sizeof(ll),0);
    rep(i,1,X.size()+1){
        rep(j,1,Y.size()+1){
            if(X[i-1]==Y[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
        }
    }
    rep(i,0,X.size()+1){
        rep(j,0,Y.size()+1) cout << dp[i][j] <<" ";
        cout << endl;
    }
    cout << dp[X.size()][Y.size()] << endl;
}
