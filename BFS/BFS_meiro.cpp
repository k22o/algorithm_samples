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
    vector<vector<char>> s(R,vector<char> ('a',C));
    string c = "";
    vector<int> check(R*C,0);
    rep(i,0,R){rep(j,0,C) cin >> s[i][j];}
    rep(i,0,R){rep(j,0,C){ c += s[i][j];}}

    queue<ipair> q;
    int start = (sy-1)*C+sx-1;
    int finish = (gy-1)*C+gx-1;
    q.push(make_pair(start,0));
    check[start] = 1;
    while (!q.empty()){
        ipair tops = q.front();
        int top = tops.first;
        q.pop();
        if(top==finish){
            cout << tops.second << endl;
            break;
        }
        for(int iy=-1;iy<=1;iy++){
            if((top<C*1 && iy==-1)||(top>=(R-1)*C && iy==1)) continue;
            for(int ix=-1;ix<=1;ix++){
                if((top%C==0 && ix ==-1) || (top%C==C-1 && ix == 1)) continue;
                if(iy*ix != 0 || (iy==0 && ix==0)) continue;
                int idx = top + iy*C + ix;
                if(c[idx]=='.' && check[idx] == 0){
                    q.push(make_pair(idx,tops.second+1));
                    check[idx] = 1;
                }
            }
        }
    }
}