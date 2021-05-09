#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)
using point = pair<double,double>;

//https://atcoder.jp/contests/abc016/submissions/me
//線分a1a2とb1b2の交差判定
point point_sub(point a, point b){
    point ans;
    ans.first = a.first-b.first;
    ans.second = a.second-b.second;
    return ans;
}

bool crossing_judge(point a1,point a2,point b1,point b2){
    point v0, v1,v2;
    double S1,S2,S3,S4;
    v0 = point_sub(a2,a1);
    v1 = point_sub(b1,a1);
    v2 = point_sub(b2,a1);
    S1 = v0.first*v1.second-v0.second*v1.first;
    S2 = v0.first*v2.second-v0.second*v2.first;
    v0 = point_sub(b2,b1);
    v1 = point_sub(a1,b1);
    v2 = point_sub(a2,b1);
    S3 = v0.first*v1.second-v0.second*v1.first;
    S4 = v0.first*v2.second-v0.second*v2.first;
    return S1*S2<0 && S3*S4<0;
}

int main(){
    point A,B;
    int N,cnt=0;
    cin >> A.first >> A.second >> B.first >> B.second >>N;
    vector<point> X(N+1);
    rep(i,0,N) cin >> X[i].first >> X[i].second;
    X[N] = X[0];

    rep(i,0,N) if(crossing_judge(A,B,X[i],X[i+1])) cnt++;
    cout << 1+int(cnt/2) << endl;
}