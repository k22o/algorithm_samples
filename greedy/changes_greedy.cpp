#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)

//https://atcoder.jp/contests/arc006/tasks/arc006_3
int main(){
    int N;
    cin >> N;
    vector<int>w(N,0);
    vector<int>stocks;
    rep(i,0,N) cin>>w[i];
    rep(i,0,N){
        int tmpMin = INF;
        int idx = 0;
        bool flag = false;
        rep(j,0,stocks.size()){
            if(stocks[j]>=w[i] && tmpMin>=stocks[j]){
                tmpMin = w[i];
                idx = j;
                flag =true;
            }
        }
        if(flag) stocks[idx] = tmpMin;
        else stocks.push_back(w[i]);
    }
    cout << stocks.size() << endl;
}
