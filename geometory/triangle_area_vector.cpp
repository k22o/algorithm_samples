#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)
using ipair = pair<ll,ll>;

//https://atcoder.jp/contests/abc002/tasks/abc002_3
int main(){
    double a[2],b[2],c[2],v1[2],v2[2];
    cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];
    v1[0] = b[0]-a[0];
    v1[1] = b[1]-a[1];
    v2[0] = c[0]-a[0];
    v2[1] = c[1]-a[1];
    cout << abs(v1[0]*v2[1]-v2[0]*v1[1])/2 << endl;
}