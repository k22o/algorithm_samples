#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)


//行列累乗-フィボナッチ
//https://cinnamo-coder.hatenablog.com/entry/2019/05/24/172153
using mat = vector<vector<ll>>;
using vec = vector<ll>;
vec dp;

vec matMulVec(mat m1, vec v1){
    vec ans(m1.size(),0);
    rep(i,0,m1.size()) rep(j,0,v1.size()) ans[i] += m1[i][j]*v1[j];
    return ans;
}
mat matDot(mat m1,mat m2){
    mat ans(m1.size(),vector<ll>(m2[0].size(),0));
    rep(i,0,m1.size()) rep(j,0,m2[0].size()) rep(k,0,m2.size()) ans[i][j] += m1[i][k]*m2[k][j];
    return ans;
}


void matPow(mat m1, ll k){
    while(k>0){
        if(k%2==1) dp = matMulVec(m1,dp);
        m1 = matDot(m1,m1);
        k = k/2;
    }
}

int main(){
    dp.assign(2,1);
    ll k;
    cin >> k;
    mat m1 = {{1,1},{1,0}};

    if (k==1||k==2) cout << "フィボナッチ数列の " <<k <<" 項目は 1 です．"  <<endl;
    else{
        matPow(m1,k-2);
        cout << "フィボナッチ数列の " <<k <<" 項目は "<< dp[0] <<" です．" <<endl;
    }
}


/*
mat add(mat m1,mat m2){
    mat ans(m1.size(),vector<ll>(m1[0].size()));
    rep(i,0,m1.size()) rep(j,0,m1[0].size()) ans[i][j] = m1[i][j]+m2[i][j];
    return ans;
}
mat sub(mat m1,mat m2){
    mat ans(m1.size(),vector<ll>(m1[0].size()));
    rep(i,0,m1.size()) rep(j,0,m1[0].size()) ans[i][j] = m1[i][j]-m2[i][j];
    return ans;
}
mat mul(mat m1,mat m2){
    mat ans(m1.size(),vector<ll>(m1[0].size()));
    rep(i,0,m1.size()) rep(j,0,m1[0].size()) ans[i][j] = m1[i][j]*m2[i][j];
    return ans;
}
mat dot(mat m1,mat m2){
    mat ans(m1.size(),vector<ll>(m2[0].size(),0));
    rep(i,0,m1.size()) rep(j,0,m2[0].size()) rep(k,0,m2.size()) ans[i][j] += m1[i][k]*m2[k][j];
    return ans;
}
*/