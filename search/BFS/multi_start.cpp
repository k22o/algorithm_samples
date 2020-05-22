#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ll = long long int;
using itpl = tuple<int,int,int>;
int wi[4] = {0,-1,0,1};
int hi[4] = {-1,0,1,0};

//https://atcoder.jp/contests/agc033/tasks/agc033_a
int main(){
    int H,W,cnt=0;
    cin >> H >> W;
    vector<vector<char>> c(H,vector<char> (W,'a'));
    string S;
    vector<vector<int>> check(H,vector<int>(W,0));
    rep(i,0,H){
        cin >> S;
        rep(j,0,W) c[i][j]=S[j];
    }

    queue<itpl> q;
    rep(i,0,H) rep(j,0,W) if(c[i][j]== '#') q.push(make_tuple(j,i,0));        

    int now_x,now_y,now_dist;
    while (!q.empty()){
        tie(now_x,now_y,now_dist) = q.front();
        q.pop();
        for(int moveIdx=0;moveIdx<4;moveIdx++){
            int x = now_x + wi[moveIdx];
            int y = now_y + hi[moveIdx];
            if(x<0||x>=W||y<0||y>=H) continue;
            if(c[y][x]=='.'){
                q.push(make_tuple(x,y,now_dist+1));
                c[y][x] = '#';
            }
        }
    }
    cout << now_dist << endl;
}