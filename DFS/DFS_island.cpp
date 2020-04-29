#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ll = long long int ;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1160&lang=jp
int main(){
    int w,h,sum=0;
    cin >> w >> h;
    vector<int> c(w*h,0),check(w*h,0);
    rep(i,0,w*h) cin>> c[i];
    stack<int> s;    
    for(int i=0;i<w*h;i++){        
        while (!s.empty()){
            int top = s.top();
            s.pop();
            for(int ix=-1;ix<=1;ix++){
                if((top<w*1 && ix==-1)||(top>=(h-1)*w && ix==1)) continue;
                for(int iy=-1;iy<=1;iy++){
                    if((top%w==0 && iy ==-1) || (top%w==w-1 && iy == 1)) continue;
                    int idx = top + ix*w + iy;
                    if(check[idx] != 2 && c[idx]==1){
                        check[idx] = 2;
                        s.push(idx);
                    }                                            
                }
            }
        }
        if (s.empty() && check[i] != 2 && c[i] == 1){
            s.push(i);   
            sum ++;    
            check[i] = 2;
        }
        else if (s.empty()) continue;
    }
    cout << sum <<endl;
}