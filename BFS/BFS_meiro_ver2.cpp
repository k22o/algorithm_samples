#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ll = long long int;
using ipair = pair<int,int>;
using itpl = tuple<int,int,int>;
int wi[4] = {0,-1,0,1};
int hi[4] = {-1,0,1,0};

//https://atcoder.jp/contests/abc007/tasks/abc007_3
int main(){
    int R,C,sy,sx,gy,gx;
    cin >> R >> C >> sy>> sx >> gy >> gx;
    vector<vector<char>> s(R,vector<char> ('a',C));
    vector<vector<int>> check(R,vector<int>(C,0));
    rep(i,0,R)rep(j,0,C) cin >> s[i][j];
    sy -=1; sx -=1;
    gy -=1; gx -=1;

    queue<itpl> q;
    q.push(make_tuple(sy,sx,0));
    check[sy][sx] = 1;
    itpl tops;
    while (!q.empty()){
        tops = q.front();
        int top1 = get<0>(tops);
        int top2 = get<1>(tops);        
        q.pop();
        if(top1==gy && top2==gx){
            cout << get<2>(tops) << endl;
            break;
        }
        for(int i=0;i<4;i++){
            int yi = top1+hi[i];
            int xi = top2+wi[i]; 
            if(s[yi][xi]=='.' && check[yi][xi]==0){
                    q.push(make_tuple(yi,xi,get<2>(tops)+1));
                    check[yi][xi] = 1;
            }            
        }
    }
}