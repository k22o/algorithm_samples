#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)


//https://atcoder.jp/contests/keyence2020/tasks/keyence2020_b
int main(){
    int N,ans=0;
    cin >> N;
    vector<int> X(N,0),L(N,0);
    vector<pair<int,int>> range(N);
    rep(i,0,N) cin >> X[i] >> L[i];
    rep(i,0,N) {
        range[i].first = X[i] + L[i];
        range[i].second = X[i] - L[i];
    }
    int cur = -1*INF;
    sort(range.begin(),range.end(),less<pair<int,int>>());
    for(int i=0;i<N;i++){
        if(cur<=range[i].second){
            ans ++;
            cur = range[i].first;
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