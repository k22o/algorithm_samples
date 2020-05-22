#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 1000000000000000
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)
 

//https://atcoder.jp/contests/abc023/tasks/abc023_d
/*
最小値を求めよ→ある値が条件を満たすのかどうか，
二部探索をもとに最小の値を探索する
*/ 
int main() {
    int N;
    cin >> N;
    vector<ll> H(N,0),S(N,0);
    rep(i,0,N) cin >> H[i] >> S[i];

    ll low = -1;
    ll high = INF;
    while(high-low>1) {
        ll mid = (high + low) / 2;
        bool flag = true;
        vector<double> tmp(N,0);
        rep(i,0,N)tmp[i] = (double)(mid - H[i])/S[i];
        sort(tmp.begin(), tmp.end()); 
        rep(i,0,N) if(i>tmp[i]){flag = false;break;}

        if(flag) high = mid;
        else low = mid;
    }
    cout << high << endl;
}