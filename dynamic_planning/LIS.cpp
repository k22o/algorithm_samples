#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)

//https://atcoder.jp/contests/chokudai_S001/tasks/chokudai_S001_h
//https://atcoder.jp/contests/abc006/tasks/abc006_4
int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i,0,N) cin >> a[i];
    vector<int> dp(N,INF);

    for(int i=0;i<N;i++){
        auto it = lower_bound(dp.begin(),dp.end(),a[i]);
        *it = a[i];
    }
    
    // question 1
    cout << lower_bound(dp.begin(),dp.end(),INF) - dp.begin() << endl;
    // question 2
    cout << N-(lower_bound(dp.begin(),dp.end(),INF) - dp.begin()) << endl;

}
