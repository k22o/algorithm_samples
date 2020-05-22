#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ll = long long int;
using ipair = pair<int,int>;
int wi[4] = {0,-1,0,1};
int hi[4] = {-1,0,1,0};

//https://atcoder.jp/contests/atc001/tasks/dfs_a
int main(){
    int H,W,sum=0;
    ipair start,goal;
    cin >> H >> W;
    string S;
    bool flag=false;
    vector<vector<char>> c(H,vector<char>(W,0));
    vector<vector<int>> check(H,vector<int>(W,0));
    rep(i,0,H){
        cin >> S;
        rep(j,0,W){
            c[i][j] = S[j];
            if(c[i][j]=='s') start = make_pair(j,i);
            if(c[i][j]=='g') goal = make_pair(j,i);
        }
    }
    stack<ipair> s;    
    //check[start.second][start.first] = 2;
    s.push(start);
    while(!s.empty()){
        int now_x,now_y;
        tie(now_x,now_y) = s.top();
        s.pop();
        for (int moveIdx=0;moveIdx<4;moveIdx++){
            int x = now_x + wi[moveIdx];
            int y = now_y + hi[moveIdx];
            if(x<0||x>=W||y<0||y>=H) continue;
            if(check[y][x] !=2 && c[y][x]=='.'){
                check[y][x] = 2;
                s.push(make_pair(x,y));            
            }
            else if(c[y][x]=='g') flag = true;
        }
    }
    if(flag) cout <<"Yes"<< endl;
    else cout <<"No"<<endl;
}