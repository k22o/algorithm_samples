#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ll = long long int;
using ipair = pair<int,int>;

//https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_e
int main(){
    int H,W,cnt=0;
    cin >> H >> W;
    vector<vector<char>> s(H,vector<char> (W,'a'));
    string c = "";
    vector<int> check(H*W,0);
    rep(i,0,H){rep(j,0,W) cin >> s[i][j];}
    rep(i,0,H){rep(j,0,W){c +=s[i][j];}}

    queue<ipair> q;
    rep(i,0,c.size()){
        if(c[i]== '#') q.push(make_pair(i,0));
    }

    ipair tops;
    while (!q.empty()){
        tops = q.front();
        int top = tops.first;
        q.pop();
        for(int iy=-1;iy<=1;iy++){
            if((top<W*1 && iy==-1)||(top>=(H-1)*W && iy==1)) continue;
            for(int ix=-1;ix<=1;ix++){
                if((top%W==0 && ix ==-1) || (top%W==W-1 && ix == 1)) continue;
                if(iy*ix != 0 || (iy==0 && ix==0)) continue;
                int idx = top + iy*W + ix;
                if(c[idx]=='.'){
                    cout << top <<" " << idx << " " << tops.second+1 << endl;
                    q.push(make_pair(idx,tops.second+1));
                    c[idx] = '#';
                }
            }
        }
    }
    cout << tops.second<<endl;
}