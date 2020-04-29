#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)



//https://atcoder.jp/contests/joi2010yo/tasks/joi2010yo_d
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> arr(n,0);
    vector<int> index_vec(k,0);
    vector<int> search_arr;
    iota(index_vec.begin(),index_vec.end(),1);
    rep(i,0,n) cin >> arr[i];

    //nCkを実現
    while(1){
        // nPkを実現　- 処理を書く
        do{
            //for(auto x:index_vec) cout << x << " ";cout << endl;
            string str= "";
            for(int i=0;i<k;i++) str += to_string(arr[index_vec[i]-1]);
            int tmp = stoi(str);
            cout << tmp << endl;
            if(find(search_arr.begin(),search_arr.end(),tmp) == search_arr.end()) search_arr.push_back(tmp);

        }while(next_permutation(index_vec.begin(),index_vec.end()));
        sort(index_vec.begin(),index_vec.end(),less<int>());
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
    cout << search_arr.size() << endl;    

}