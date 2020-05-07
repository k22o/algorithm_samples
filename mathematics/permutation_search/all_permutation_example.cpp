#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)

//https://atcoder.jp/contests/abc054/tasks/abc054_c
int main(){
    int N,M,tmp1,tmp2,ans=0;
    cin >> N >> M;
    vector<vector<int>> mat(N,vector<int>(N,0));    
    vector<int> arr(N);
    iota(arr.begin(),arr.end(),1);
    rep(i,0,M){
        cin >> tmp1 >> tmp2;
        mat[tmp1-1][tmp2-1] = 1;         
        mat[tmp2-1][tmp1-1] = 1;         
    }
    bool flag;
    do{
        if(arr[0] != 1) continue;
        flag = true;
        for(int i=0;i<N-1;i++){
            if(mat[arr[i]-1][arr[i+1]-1] == 0){
                flag = false;
                break;
            } 
        }
        if(flag) ans ++;
    }while(next_permutation(arr.begin(),arr.end()));
    cout << ans << endl;
}