#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)



//https://atcoder.jp/contests/joi2010yo/tasks/joi2010yo_d
int main(){
    int n,k,cnt =0;
    cin >> n >> k;
    vector<int> index_vec(k,0);
    iota(index_vec.begin(),index_vec.end(),1);

    //nCkを実現
    while(1){

        for(auto x:index_vec) cout << x << " ";
        cout << endl;
        cnt ++;

        if (index_vec[k-1]==n && index_vec[0]==n-k+1) break;
        else{
            for(int i=k-1;i>=0;i--){
                if(index_vec[i] < n-k+1+i) {
                    index_vec[i] = index_vec[i]+1;
                    for(int j=1;j<k-i;j++){index_vec[j+i] = index_vec[i] + j;}
                    break;
                }
            }
        }
    }
    cout << "permutataion: " << cnt << endl;
}