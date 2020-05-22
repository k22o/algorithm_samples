#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ll = long long int;
using itpl = tuple<int,int,int>;
int wi[4] = {0,-1,0,1};
int hi[4] = {-1,0,1,0};

//https://atcoder.jp/contests/abc007/tasks/abc007_3
int main(){
    int R,C,sy,sx,gy,gx;
    string S;
    cin >> R >> C >> sy>> sx >> gy >> gx;
    sx --;sy --;gx --;gy --;
    vector<vector<char>> c(R,vector<char> (C,'a'));
    vector<vector<int>> check(R,vector<int>(C,0));
    rep(i,0,R){
        cin >> S;
        rep(j,0,C) c[i][j] = S[j];
    }
    
    queue<itpl> q;    
    q.push(make_tuple(sx,sy,0));
    check[sy][sx] = 1;

    while (!q.empty()){
        int now_x,now_y,now_dist;
        tie(now_x,now_y,now_dist) = q.front();
        q.pop();
        if(now_x==gx && now_y==gy){
            cout << now_dist << endl;
            break;
        }
        for(int moveIdx=0;moveIdx<4;moveIdx++){
            int x = now_x + wi[moveIdx];
            int y = now_y + hi[moveIdx];
            if(x<0||x>=C||y<0||y>=R) continue;
            if(c[y][x]=='.' && check[y][x]!=1){
                q.push(make_tuple(x,y,now_dist+1));
                check[y][x] = 1;
            }
        }
    }    
}