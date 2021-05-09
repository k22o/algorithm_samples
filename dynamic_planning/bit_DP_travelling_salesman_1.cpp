#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 1000000000
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)
using itpl = tuple<int,int>;


vector<vector<ll>> dp;
vector<vector<ll>> dist;

ll rec(ll bit, ll v){
    ll N = dp[0].size();
    if(dp[bit][v]!=-1) return dp[bit][v];//未探索のとき
    if(bit == (1<<v)){
        dp[bit][v] = 0;
        return 0; 
    }
    ll result = INF;
    ll pre_bit = bit & ~(1<<v);

    for(ll u=0;u<N;u++){//1が立っているところを探索
        if(!(pre_bit & (1<<u))) continue;
        ll tmp = rec(pre_bit,u) + dist[u][v];
        if(result > tmp) result = tmp;
    }
    dp[bit][v] = result;
    return result;
}

//巡回セールスマン問題
//もしスタート地点まで戻らないなら…
//https://qiita.com/drken/items/7c6ff2aa4d8fce1c9361#11-bit-dp
int main(){
    ll N,E,s,t,d;
    cin >> N >> E;

    dist.assign(N,vector<ll>(N,0));
    dp.assign(((1<<N)+1),vector<ll>(N,-1));
    rep(i,0,E){
        cin >> s >> t >> d;
        dist[s][t] = d;
        dist[t][s] = d;
    }
    ll ans = INF;
    rep(i,0,N){
        ll tmp = rec((1<<N)-1,i);
        if(ans>tmp) ans = tmp;
    }
    cout << ans << endl;
}
