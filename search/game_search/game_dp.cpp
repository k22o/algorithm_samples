#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ipair = pair<int,int>;


//https://atcoder.jp/contests/tdpc/tasks/tdpc_game

int main(){
    int A,B,total=0;
    cin >> A >> B;
    vector<int>a(A),b(B);
    rep(i,0,A){cin >>a[i];total +=a[i];}
    rep(i,0,B){cin >>b[i];total +=b[i];}
    int playerIdx = (A+B)%2;
    vector<vector<int>> dp(A+1,vector<int>(B+1,0));
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int sIdx = (A+B)%2;//sIdx==0 :bさんから
    rep(i,0,A+1){
        rep(j,0,B+1){
            if(i==0&&j==0)continue;
            else if (i==0 &&j>0&&(i+j)%2==sIdx) dp[i][j] = dp[i][j-1] + b[j-1];
            else if (i==0 &&j>0&&(i+j)%2!=sIdx) dp[i][j] = dp[i][j-1] - b[j-1];
            else if (j==0 &&i>0&&(i+j)%2==sIdx) dp[i][j] = dp[i-1][j] + a[i-1];
            else if (j==0 &&i>0&&(i+j)%2!=sIdx) dp[i][j] = dp[i-1][j] - a[i-1];
            else if ((i+j)%2==sIdx)dp[i][j] = max(dp[i-1][j]+a[i-1],dp[i][j-1]+b[j-1]);
            else if ((i+j)%2!=sIdx)dp[i][j] = min(dp[i-1][j]-a[i-1],dp[i][j-1]-b[j-1]);
        }
    }
    cout << (total+dp[A][B])/2 << endl;
}