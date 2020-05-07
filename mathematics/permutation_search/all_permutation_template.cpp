#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)

int main(){
    int N;
    N=3;
    vector<int> arr(N);
    iota(arr.begin(),arr.end(),1);
    //1-Nまでの順列 N!通り
    do{
        for(auto x:arr) cout << x << " ";
        cout << endl; 
    }while(next_permutation(arr.begin(),arr.end()));
}

/*
注意：next permutationは，辞書順に並べるので，
[1,2,3,4]などの，sortされたものから開始しないといけない．
[4,3,1,2]から始めると，
[4,3,1,2],[4,3,2,1]で終わってしまう！
 
*/