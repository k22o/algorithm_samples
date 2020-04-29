#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)

//https://atcoder.jp/contests/abc164/tasks/abc164_d
int main(){
    string S;
    cin >> S;
    int ans = 0,digit = 1;
    vector<int> a(S.size()+1,0);
    rep(i,0,S.size()) a[i] = S[i] - '0';

    for(int i=S.size()-2;i>=0;i--){
        digit = (digit*10) %2019;
        a[i] = ((a[i]*digit)%2019 + a[i+1])%2019;
        //cout << i << " "<< digit <<" "<< a[i] << endl;
    }
    for(int i=0;i<2019;i++){
        int cnt = (int)count(a.begin(),a.end(),i);
        ans += cnt*(cnt-1)/2;
    }
    cout << ans << endl;
}