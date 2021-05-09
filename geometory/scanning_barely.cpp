#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using point = pair<double,double>;


//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1132&lang=jp
//"ぎりぎりを考える"

point point_calc(point a, point b, char flag){
    point ans;
    if (flag=='a'){ans.first = a.first+b.first;ans.second = a.second+b.second;}
    else if (flag=='s'){ans.first = a.first-b.first;ans.second = a.second-b.second;}
    else if (flag=='m'){ans.first = a.first*b.first;ans.second = a.second*b.second;}
    else if (flag=='d'){ans.first = a.first/b.first;ans.second = a.second/b.second;}
    return ans;
}
double vec_norm(point a){
    return sqrt(a.first*a.first+a.second*a.second);
}
bool circle_judge(point a, point p, double r){
    double d = vec_norm(point_calc(a,p,'s'));
    if(d<=r+1e-6) return true;
    else return false;
}

int main(){
    vector<int> ans_arr;
    while(1){
        int N,ans=1;
        cin >> N;
        if(N==0) break;
        vector<point> x(N);
        rep(i,0,N) cin >> x[i].first >> x[i].second;
        rep(i,0,N-1){
            rep(j,i+1,N){
                // a,b:円周上の点，c:abの中点，p:中心
                point a,b,c,cp,ab,p;
                point div = {2.0,2.0};
                a = x[i];b=x[j];
                c = point_calc(point_calc(a,b,'a'),div,'d');
                ab = point_calc(b,a,'s');
                double ab_norm2 = ab.first*ab.first+ab.second*ab.second;
                if(ab_norm2>4) continue;
                double dist = sqrt(1-ab_norm2/4);
                //abに垂直で長さdistのベクトルcpを作成
                cp.first = dist*ab.second/sqrt(ab_norm2);
                cp.second = dist*(-1)*ab.first/sqrt(ab_norm2);
                rep(k,0,2){
                    if(k==0) p = point_calc(c,cp,'a');
                    else if(k==1) p = point_calc(c,cp,'s');
                    int cnt =0;
                    rep(l,0,N) if(circle_judge(x[l],p,1)) cnt ++;
                    ans = max(ans,cnt);
                }
            }
        }
        ans_arr.push_back(ans);
    }
    for(auto z:ans_arr) cout << z << endl;
}