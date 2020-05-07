#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
#define INF 100000000

int main(){
    int N,M,cnt=0;
    N= 5;
    M = 4;
    //1~Nの中からM個を選ぶ重複組み合わせを列挙する
    vector<int> vec(M,1);
    while(1){
        cnt ++ ;
        rep(i,0,M) cout << vec[i] <<" ";
        cout << endl;
     
        int idx = M-1;
        while(vec[idx]==N) idx--;
        if(idx<0) break;
        vec[idx] ++;
        rep(i,idx+1,M) vec[i] = vec[idx];
    }

    cout << cnt << endl;
}
