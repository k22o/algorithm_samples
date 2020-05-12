#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ipair = pair<int,int>;
using itpl = tuple<int,int>;

//https://atcoder.jp/contests/abc167/tasks/abc167_c
int main(){
    int N,M,X;
    cin >> N >> M >> X;
    vector<int>C(N);
    vector<vector<int>> A(N,vector<int>(M,0));
    rep(i,0,N){
        cin >> C[i];
        rep(j,0,M) cin >> A[i][j];
    }

    int minCost = INF;
    for(int bit = 0;bit <(1<<N);bit++){
        int tmpCost = 0;
        vector<int> cnt(M,0);
        for(int i=0;i<N;i++){
            if(bit & (1 << i)){
                tmpCost += C[i];
                rep(j,0,M) cnt[j] +=A[i][j];
            }            
        }
        bool flag=true;
        rep(j,0,M) if(cnt[j]<X){flag=false;break;}
        if(flag && minCost>tmpCost)minCost = tmpCost;
    }
    if(minCost==INF) cout << "-1" << endl;
    else cout << minCost << endl;
}