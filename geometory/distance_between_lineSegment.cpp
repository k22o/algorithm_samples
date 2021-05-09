#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using point = pair<double,double>;


//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2661

point point_sub(point a, point b){
    point ans;
    ans.first = a.first-b.first;
    ans.second = a.second-b.second;
    return ans;
}

//点と線分の距離 https://tgws.plus/ul/ul31.html
//点s,tを結ぶ線分と点pとの距離
double calc_dist_lineSegment_point(point s, point t, point p){
    point st = point_sub(t,s);
    point sp = point_sub(p,s);
    point tp = point_sub(p,t);    
    double st_norm2 = st.first*st.first+st.second*st.second;
    double sp_norm2 = sp.first*sp.first+sp.second*sp.second;
    double tp_norm2 = tp.first*tp.first+tp.second*tp.second;
    double st_sp_dot = ((sp.first*st.first)+(sp.second*st.second));
    if(st_sp_dot<=0) return sqrt(sp_norm2);
    else if(st_sp_dot>=st_norm2) return sqrt(tp_norm2);
    else return sqrt(sp_norm2-st_sp_dot*st_sp_dot/st_norm2);
}

//線分a1a2とb1b2の交差判定
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

//線分a1a2とb1b2の距離
double calc_lineSegment_dist(point a1,point a2,point b1, point b2){    
    if(a1==a2 && b1==b2) return sqrt(pow(a1.first-b1.first,2)+pow(a1.second-b1.second,2));
    else if(a1==a2) return calc_dist_lineSegment_point(b1,b2,a1);
    else if(b1==b2) return calc_dist_lineSegment_point(a1,a2,b1);
    else if (crossing_judge(a1,a2,b1,b2)) return 0;
    else{
        vector<double> tmp(4);
        tmp[0] = calc_dist_lineSegment_point(a1,a2,b1);
        tmp[1] = calc_dist_lineSegment_point(a1,a2,b2);
        tmp[2] = calc_dist_lineSegment_point(b1,b2,a1);
        tmp[3] = calc_dist_lineSegment_point(b1,b2,a2);
        return *min_element(tmp.begin(),tmp.end());
    }
}

int main(){
    int N1,N2;
    cin >> N1;
    vector<point> a(N1+2);
    a[0].first = 0;a[N1+1].first = 1000;
    a[0].second = 0;a[N1+1].second = 0;
    rep(i,1,N1+1) cin >> a[i].first >> a[i].second;
    cin >> N2;
    vector<point> b(N2+2);
    b[0].first = 0;b[N2+1].first = 1000;
    b[0].second = 1000;b[N2+1].second = 1000;
    rep(i,1,N2+1) cin >> b[i].first >> b[i].second;

    double ans = INF;
    rep(i,0,N1+1)rep(j,0,N2+1) ans = min(ans,calc_lineSegment_dist(a[i],a[i+1],b[j],b[j+1]));
    cout <<  fixed << setprecision(10) << ans << endl;
}