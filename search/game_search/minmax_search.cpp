#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ipair = pair<int,int>;


//https://atcoder.jp/contests/abc025/tasks/abc025_c
//minmaxアルゴリズム(深さ優先+評価関数)

int b[2][3],c[3][2];

//ノードの最後での得点計算
int calc(int m[3][3]){
    int ans=0;
    rep(i,0,2)rep(j,0,3){
        if(m[i][j]==m[i+1][j]) ans+=b[i][j];
        else ans -= b[i][j];
    }
    rep(i,0,3)rep(j,0,2){
        if(m[i][j]==m[i][j+1]) ans +=c[i][j];
        else ans -= c[i][j];
    }
    return ans;
}

//platerIdx=0は評価関数が最大になるように行動
//platerIdx=1は評価関数が最小になるように行動
int minmax(int ply,int playerIdx, int gameState[3][3]){
    vector<int> score_arr;//ある深さでのスコアをためておく
    if(ply==9) {return calc(gameState);}
    rep(i,0,3)rep(j,0,3){
        if(gameState[i][j]!=-1) continue;
        else if(playerIdx==0) gameState[i][j]=0;
        else if(playerIdx==1) gameState[i][j]=1;
        score_arr.push_back(minmax(ply+1,(playerIdx+1)%2, gameState));
        gameState[i][j] = -1;
    }
    //その深さでの最良手を返す
    sort(score_arr.begin(),score_arr.end());
    if (playerIdx%2==0) return score_arr.back();  
    else if (playerIdx%2==1) return score_arr.front();  

}

int main(){
    int total = 0;
    int m[3][3];
    rep(i,0,3)rep(j,0,3) m[i][j]=-1;
    rep(i,0,2) rep(j,0,3){cin >> b[i][j];total+=b[i][j];}
    rep(i,0,3) rep(j,0,2){cin >> c[i][j];total+=c[i][j];}
    int ans = minmax(0,0,m);

    cout << (total+ans)/2 << endl;
    cout << (total-ans)/2 << endl;
}