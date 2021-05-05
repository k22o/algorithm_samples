#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ll = long long int;
using ipair = pair<int,int>;

//https://atcoder.jp/contests/abc007/tasks/abc007_3
int main(){

    int R,C,sy,sx,gy,gx;
    cin >> R >> C >> sy>> sx >> gy >> gx;
    sx --;sy --;gx --;gy --;

    vector<vector<char>> c(R,vector<char> (C,'a'));
    vector<vector<int>> shortest(R,vector<int>(C,INF));
    rep(i,0,R){
        string str;
        cin >> str;
        rep(j,0,C) c[i][j] = str[j];
    }

    queue<ipair> q;
    q.push(make_pair(sx,sy));
    shortest[sy][sx] = 0;

    int ri[4] = {0,-1,0,1};
    int ci[4] = {-1,0,1,0};

    while(!q.empty()) {
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        
        if(x == gx && y == gy) {
            break;
        }

        rep(moveIdx,0,4) {
            int nx = x + ci[moveIdx];
            int ny = y + ri[moveIdx];
            if(nx<0||nx>=C||ny<0||ny>=R) continue;
            if(c[ny][nx]=='.' && shortest[ny][nx] > shortest[y][x]+1) {
                q.push(make_pair(nx,ny));
                shortest[ny][nx] = shortest[y][x] + 1;
            }
        }        
    }
    cout << shortest[gy][gx] << endl;

}
