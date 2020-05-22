#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ipair = pair<int,int>;

//https://atcoder.jp/contests/tdpc/tasks/tdpc_iwi
//https://algo-logic.info/range-dp/

vector<vector<int>> dp;
//メモ再帰
int rec(string s, int l, int r){ //区間[l,r)
    if(abs(l-r)<=1) return 0;//これ以上範囲が狭まらない
    if(r-l==3){//最小単位のとき，取り除ける要素数を返す
        if(s.substr(l,r-l)=="iwi") return 3;
        else return 0;
    }

    if(dp[l][r] != -1) return dp[l][r];

    //[l,r)の範囲で全て取り除けるとき
    //[i, ..... wi)の形のとき
    if(s[l]=='i' && s[r-2]=='w' && s[r-1]=='i' && rec(s,l+1,r-2)== r-l-3){
        if(dp[l][r]<r-l) dp[l][r] = r-l;}
    if(s[l]=='i' && s[l+1]=='w' && s[r-1]=='i' && rec(s,l+2,r-1)== r-l-3){
        if(dp[l][r]<r-l) dp[l][r] = r-l;}

    //[l,r)のすべては取り除けないとき
    //i番目までのrecとi番目までのrecの和と計算
    for(int i=l+1;i<=r-1;i++){
        int tmp2 = rec(s,l,i)+rec(s,i,r);
        if(dp[l][r]<tmp2) dp[l][r] = tmp2;
    }
    return dp[l][r];
}

int main(){
    string s;
    cin >> s;
    dp.assign(s.size()+1,vector<int>(s.size()+1,-1));
    int ans = rec(s,0,s.size());
    cout << ans/3 << endl;

}