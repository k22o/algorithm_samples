#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)

//https://atcoder.jp/contests/abc085/tasks/abc085_b
int main(){
    int N;
    cin >> N;
    vector<int> d(N);
    rep(i,0,N) cin >> d[i];
    
    // setは，重複無し，小さい順．
    set<int> s(d.begin(),d.end());
    //vector<int> v(s.begin()s.end());
    cout << s.size() << endl;

}
