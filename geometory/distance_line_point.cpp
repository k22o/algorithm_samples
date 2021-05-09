#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)
using point = pair<double,double>;

//https://atcoder.jp/contests/arc042/submissions/me
//点pと直線stの距離
double calc_dist_line_point(point s, point t, point p){
    if(s.first != t.first){
        // y = ax + b
        double a = (t.second-s.second)/(t.first-s.first);
        double b = s.second - a*s.first;
        return abs(a*p.first-p.second+b)/sqrt(a*a+1);
    }
    else return abs(p.second-s.second);
}

int main(){
    point x0;
    int N;
    cin >> x0.first >> x0.second >> N;
    vector<point> x(N+1);
    vector<double> dist(N);
    rep(i,0,N) cin >> x[i].first >> x[i].second;
    x[N] = x[0];
    rep(i,0,N) dist[i] = calc_dist_line_point(x[i],x[i+1],x0);
    cout << fixed << setprecision(10) << *min_element(dist.begin(),dist.end()) << endl;
}