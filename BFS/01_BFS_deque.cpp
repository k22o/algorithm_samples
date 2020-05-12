#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ll = long long int;
using ituple = tuple<int,int,int,int>;

int wi[4] = {0,-1,0,1};
int hi[4] = {-1,0,1,0};

//https://atcoder.jp/contests/arc005/tasks/arc005_3
int main(){
    int H,W,cnt=0;
    int sx,sy,gx,gy;
    bool flag = false;

    cin >> H >> W;
    vector<vector<char>> c(H,vector<char> (W,'a'));
    vector<vector<int>> check(H,vector<int> (W,0));
    rep(i,0,H){
        rep(j,0,W){
            cin >> c[i][j];
            if(c[i][j]== 's') {sy = i; sx = j;}
            if(c[i][j]== 'g') {gy = i; gx = j;}
        }
    }

    deque<ituple> q;
    q.push_front(make_tuple(sx,sy,0,0));
    check[sy][sx] = 1;

    while (!q.empty()){
        int now_x,now_y,now_dist,now_break;
        tie(now_x,now_y,now_dist,now_break) = q.front();
        q.pop_front();
   
        if(now_x==gx && now_y==gy && now_break<=2){
            cout << "YES" << endl;
            flag = true;
            break;
        }
        for(int moveIdx=0;moveIdx<4;moveIdx++){
            int x = now_x + wi[moveIdx];
            int y = now_y + hi[moveIdx];
            if(x<0||x>=W||y<0||y>=H) continue;

            if(check[y][x] == 0  && c[y][x]!='#'){
                q.push_front(make_tuple(x,y,now_dist+1,now_break));
                check[y][x] =1;
            }
            else if(check[y][x] == 0 && c[y][x]=='#' && now_break<2){
                q.push_back(make_tuple(x,y,now_dist+1,now_break+1));
                check[y][x] =1;
            }
        }
    }
    if(!flag) cout << "NO" <<endl;
}