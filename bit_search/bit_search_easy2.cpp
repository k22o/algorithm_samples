#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)



//https://atcoder.jp/contests/arc029/tasks/arc029_1
int main(){
    int N,sum,team1,team2;
    cin >> N;
    vector<int> t(N,0);
    rep(i,0,N) cin >> t[i];    
    int minTime = INF;
    for(int bit = 0;bit <(1<<N);bit++){
        team1 = 0;
        team2 = 0;
        for (int i=0;i<N;i++){
            if(bit & (1<<i)) team1 += t[i];
            else team2 +=t[i];
        }
        if(minTime>max(team1,team2)) minTime = max(team1,team2);
    }
    cout << minTime << endl;
}