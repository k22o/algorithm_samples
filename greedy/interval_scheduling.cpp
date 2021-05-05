#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)

/*
区間の終端 (もしくは始端) でソートして選択していく
*/


//https://atcoder.jp/contests/keyence2020/tasks/keyence2020_b
int main(){
    int N;
    cin >> N;
    vector<int> X(N,0),L(N,0);
    vector<pair<int,int>> interval(N);
    rep(i,0,N) cin >> X[i] >> L[i];
    rep(i,0,N) {
        interval[i].first = X[i] + L[i];
        interval[i].second = X[i] - L[i];
    }

    int ans = 0;
    int cur = -1*INF;
    sort(interval.begin(),interval.end(),less<pair<int,int>>());
    rep(i,0,N){
        if(cur<=interval[i].second){
            ans ++;
            cur = interval[i].first;
        }
    }
    cout << ans << endl;
}

/*
//https://atcoder.jp/contests/abc103/tasks/abc103_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)

int main(){
    int N,M,tmp1,tmp2,ans=0;
    cin >> N >> M;
    vector<pair<int,int>> a(M);
    rep(i,0,M){
        cin >> tmp1 >> tmp2;
        a[i].first = tmp2;
        a[i].second = tmp1;
    }
    sort(a.begin(),a.end(),less<pair<int,int>>());
    int cur = -1;
    for(int i=0;i<M;i++){
        if( cur <= a[i].second){
            ans ++;
            cur = a[i].first;
        }
    }
    cout << ans << endl;
}
*/