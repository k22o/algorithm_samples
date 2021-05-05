#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ipair = pair<int,int>;

//https://atcoder.jp/contests/atc001/tasks/dfs_a
int main() {
    int H,W;
    cin >> H >> W;
    ipair start,goal;

    //input
    vector<vector<char>> c(H,vector<char>(W,0));
    rep(h,0,H){
        string str;
        cin >> str;
        rep(w,0,W){
            c[h][w] = str[w];
            if(c[h][w]=='s') start = make_pair(w,h); 
            if(c[h][w]=='g') goal = make_pair(w,h); 
        }
    }

    //DFS
    stack<ipair> s;
    vector<vector<bool>> visited(H,vector<bool>(W,false));
    s.push(start);

    int wi[4] = {0,-1,0,1};
    int hi[4] = {-1,0,1,0};    

    while(!s.empty()){
        int x,y;
        tie(x, y) = s.top();
        s.pop();

        if (make_pair(x,y) == goal) {
            cout << "Yes" << endl;
            return 0;
        }

        rep(moveIdx,0,4) {
            int nx = x + wi[moveIdx];
            int ny = y + hi[moveIdx];
            if(nx<0 || ny<0 || nx>=W || ny>=H) continue; //index out of bounds
            if(c[ny][nx]!='#' && !visited[ny][nx]){
                s.push(make_pair(nx,ny));
                visited[ny][nx] = true;
            }
        }
    }
    cout << "No" << endl;
}


