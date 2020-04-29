#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ll = long long int;
using ituple = tuple<int,int,int>;

//https://atcoder.jp/contests/arc005/tasks/arc005_3
int main(){
    int H,W,cnt=0,start,goal;
    cin >> H >> W;
    vector<vector<char>> s(H,vector<char> (W,'a'));
    string c = "";
    vector<int> check(H*W,0);
    rep(i,0,H){rep(j,0,W) cin >> s[i][j];}
    rep(i,0,H){rep(j,0,W){c +=s[i][j];}}
    rep(i,0,c.size()){
        if(c[i]== 's') start = i;
        if(c[i]== 'g') goal = i;
    }

    bool flag = false;

    deque<ituple> q;
    q.push_front(make_tuple(start,0,0));
    check[start] = 0;
    ituple tops;

    while (!q.empty()){
        tops = q.front();
        int top = get<0>(tops);
        check[top] = 1;
        q.pop_front();
        if(top==goal && get<2>(tops)<=2){
            cout << "YES" << endl;
            flag = true;
            break;
        }
        for(int iy=-1;iy<=1;iy++){
            if((top<W*1 && iy==-1)||(top>=(H-1)*W && iy==1)) continue;
            for(int ix=-1;ix<=1;ix++){
                if((top%W==0 && ix ==-1) || (top%W==W-1 && ix == 1)) continue;
                if(iy*ix != 0 || (iy==0 && ix==0)) continue;
                int idx = top + iy*W + ix;
                if(check[idx] == 0  && c[idx]!='#'){
                    //cout << top <<" " << idx << " " << get<1>(tops)+1 <<" "<< get<2>(tops) << endl;
                    q.push_front(make_tuple(idx,get<1>(tops)+1,get<2>(tops)));
                }
                else if(check[idx] == 0 && c[idx]=='#' && get<2>(tops)<2){
                    //cout << top <<" " << idx << " " << get<1>(tops)+1 <<" "<< get<2>(tops)+1 <<endl;
                    q.push_back(make_tuple(idx,get<1>(tops)+1,get<2>(tops)+1));
                }
            }
        }
    }
    if(!flag) cout << "NO" <<endl;
}