#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
#define INF 100000000

int main(){
    int N,M,cnt=0;
    N= 4;
    M = 3;
    //1~Nの中からM個を選ぶ重複順列を列挙する
    vector<int> vec(M,1);
    while(1){
        cnt ++ ;
        rep(i,0,M) cout << vec[i] <<" ";
        cout << endl;
     
        int idx = M-1;
        while(vec[idx]==N) {
            vec[idx]=1;
            idx--;
        }
        if(idx<0) break;
        vec[idx] ++;
    }

    cout << cnt << endl;
}
