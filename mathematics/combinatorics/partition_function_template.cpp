#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using namespace std;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ipair = std::pair<int,int>;

// 分割数　nをk個に分割する
int partition(int n, int k){
    vector<vector<int>> P(n+1,vector<int>(k+1,0));
    rep(j,0,k+1) P[0][j] = 1;
    rep(i,1,n+1){
        rep(j,1,k+1){
            P[i][j] = P[i][j-1] + (i-j>=0 ? P[i-j][j] : 0);
        }
    }
    return P[n][k];
}

int main() {
    int n,k;
    cin >> n >> k;
    cout << partition(n, k) << endl;


}

//https://yukicoder.me/problems/no/269
/*
int partition(int n, int k){
    vector<vector<int>> P(n+1,vector<int>(k+1,0));
    rep(j,0,k+1) P[0][j] = 1;
    rep(i,1,n+1){
        rep(j,1,k+1){
            P[i][j] = P[i][j-1] + (i-j>=0 ? P[i-j][j] : 0);
            P[i][j] %= (int)1e9+7;
        }
    }
    return P[n][k];
}

int main() {
    int n,s,k;
    cin >> n >> s >> k;
    s -= k*n*(n-1)/2;
    if(s<0) cout << 0 << endl;
    else cout << partition(s, n) << endl;
}
*/