#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ll = long long int;
using itpl = tuple<int,int,int>;
int wi[4] = {0,-1,0,1};
int hi[4] = {-1,0,1,0};

//https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_e
int main(){
    int H,W,N,eats = 1;
    itpl start;
    cin >> H >> W >> N;    
    vector<vector<char>> c(H,vector<char> (W,'a'));
    string S ;
    vector<vector<int>> check(H,vector<int>(W,0));
    rep(i,0,H){
        cin >> S;
        rep(j,0,W){
            c[i][j] = S[j];
            if(c[i][j]=='S'){
                start = make_tuple(j,i,0);
                check[i][j] = 1;
            }
        }
    }

    queue<itpl> q;
    q.push(start);
    while (!q.empty()){
        int now_x,now_y,now_dist;
        tie(now_x,now_y,now_dist) = q.front();
        //cout << now_x << " "<< now_y << " "<< now_dist << endl;
        q.pop();

        if(check[now_y][now_x] !=2 && c[now_y][now_x] !='X' && c[now_y][now_x] !='.' && c[now_y][now_x] !='S'){
            if(eats == c[now_y][now_x] -'0'){
                eats += 1;
                check[now_y][now_x] = 2;
                rep(i,0,H) rep(j,0,W) if(check[i][j]==1) check[i][j]=0;
                while(!q.empty()) q.pop();
            }
        }
        if(eats==N+1){
            cout << now_dist << endl;
            break;
        }
        for(int moveIdx=0;moveIdx<4;moveIdx++){
            int x = now_x + wi[moveIdx];
            int y = now_y + hi[moveIdx];
            if(x<0||x>=W||y<0||y>=H) continue;
            if(c[y][x]!='X' && check[y][x] != 1){
                q.push(make_tuple(x,y,now_dist+1));
                check[y][x] = 1;
            }
        }
    }
}