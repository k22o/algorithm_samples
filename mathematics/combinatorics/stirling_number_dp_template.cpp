#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 1000000000000000LL
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)
using ipair = std::pair<ll,ll>;



const ll MOD = (ll)1e9+7;
//stirling数をDPで求める
ll stirling_num(ll n,ll k){
    vector<vector<ll>> dp(n+1,vector<ll>(k+1,0));
    dp[0][0] = 1;
    rep(i,1,n+1){
        rep(j,1,k+1){
            //dp[i][j] = dp[i-1][j-1]+j*dp[i-1][j];
            dp[i][j] = (dp[i-1][j-1]+j*dp[i-1][j]%MOD)%MOD;
        }
    }
    return dp[n][k];
}


int main(){
    ll n,k;
    cin >> n >> k;
    cout << stirling_num(n,k) << endl;
}