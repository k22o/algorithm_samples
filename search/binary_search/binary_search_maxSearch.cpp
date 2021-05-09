#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)

//https://atcoder.jp/contests/abc034/tasks/abc034_d
int main() {
    int N, K;
    cin >> N >> K;
    vector<double> w(N,0), p(N,0);
    rep(i,0,N) cin >> w[i] >> p[i];

    double high = 101;
    double low = 0;
    double mid,sum;
    bool flag;

    //doubleなのでhigh-low>1は使えない．100回ループする
    rep(i,0,100){
         mid = (high + low) / 2;
        vector<double>tmp(N); //必要な塩の量
        rep(i,0,N) tmp[i] = w[i] *(p[i]-mid);
        sort(tmp.begin(),tmp.end(),greater<double>());
        sum = accumulate(tmp.begin(),tmp.begin()+K,0.0);
        flag = (sum>=0) ? true : false; 

        if(flag) low = mid;
        else high = mid;
    }
 
    cout << fixed << setprecision(10) << low << endl;
 
    return 0;
}