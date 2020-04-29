#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ll = long long int;
using ipair = pair<int,int>;

//https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_e
int main(){
    int H,W,N,start,eats = 1;
    cin >> H >> W >> N;
    vector<vector<char>> s(H,vector<char> (W,'a'));
    string c = "";
    vector<int> check(H*W,0);
    rep(i,0,H){rep(j,0,W) cin >> s[i][j];}
    rep(i,0,H){
        rep(j,0,W){
            c +=s[i][j];
            if(s[i][j]== 'S') start = c.size()-1;
        }
    }

    queue<ipair> q;
    q.push(make_pair(start,0));
    while (!q.empty()){
        ipair tops = q.front();
        int top = tops.first;
        q.pop();
        if(check[top] == 0 && c[top] !='X' && c[top] !='.' && c[top] !='S'){
            cout << atoi(c.substr(top,1).c_str()) << endl;
            if(eats == atoi(c.substr(top,1).c_str())){
                eats += 1;
                check[top] = 2;
                rep(i,0,check.size()){
                    if(check[i]==1) check[i]=0;
                }
                while(!q.empty()) q.pop();
            }
        }
        if(eats==N+1){
            cout << tops.second << endl;
            break;
        }
        for(int iy=-1;iy<=1;iy++){
            if((top<W*1 && iy==-1)||(top>=(H-1)*W && iy==1)) continue;
            for(int ix=-1;ix<=1;ix++){
                if((top%W==0 && ix ==-1) || (top%W==W-1 && ix == 1)) continue;
                if(iy*ix != 0 || (iy==0 && ix==0)) continue;
                int idx = top + iy*W + ix;
                if(c[idx]!='X' && check[idx] != 1){
                    cout << tops.first << " " << idx <<" " << tops.second << " " << eats << endl;
                    q.push(make_pair(idx,tops.second+1));
                    check[top] = 1;
                }
            }
        }
    }
}