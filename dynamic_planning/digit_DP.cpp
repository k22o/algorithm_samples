#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)


//https://atcoder.jp/contests/tdpc/tasks/tdpc_number
//https://torus711.hatenablog.com/entry/20150423/1429794075 コード参照
//https://algo-logic.info/digit-dp/ 考え方はこちらを参照．
int main(){
    ll digit,D,MOD = 1e9+7;
    string S;
    cin >> D >> S;
    digit = S.size();
    ll dp[digit+1][2][D];//桁＊未満＊カウンター
    fill((ll*)dp, (ll*)dp + sizeof(dp)/sizeof(ll),0);
    dp[0][0][0]=1;
    for(int i=1;i<=digit;i++){
        ll num = S[i-1] -'0';//数値に変換

        for(int j=0;j<2;j++){
            for(int k=0;k<D;k++){
                for(int d =0;d<=(j?9:num);d++){
                    dp[i][j||d<num][(d+k)%D] += dp[i-1][j][k];
                    dp[i][j||d<num][(d+k)%D] %= MOD;
                }
            }
        }
    }
    cout << (dp[digit][0][0] + dp[digit][1][0]-1)%MOD << endl;
}
