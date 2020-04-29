#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)

//https://atcoder.jp/contests/arc074/tasks/arc074_b
int main(){
    int N;
    cin >> N;
    vector<int> a(3*N);
    rep(i,0,3*N) cin >> a[i];
    priority_queue<int,vector<int>,greater<int>> q_pre;//大きい方から
    priority_queue<int,vector<int>,less<int>> q_post;//小さい方から
    vector<int> sum_pre(N+1,0),sum_post(N+1,0),result(N+1,0);
    rep(i,0,N) q_pre.push(a[i]);
    rep(i,2*N,3*N) q_post.push(a[i]);
    
    sum_pre[0] = accumulate(a.begin(),a.begin()+N,0);
    for(int i=0;i<N;i++){
        q_pre.push(a[N+i]);
        int tmp = q_pre.top();
        q_pre.pop();
        sum_pre[i+1] = sum_pre[i] - tmp + a[N+i];
    }
    sum_post[N] = accumulate(a.end()-N,a.end(),0);
    for(int i=N-1;i>=0;i--){
        q_post.push(a[N+i]);
        int tmp = q_post.top();
        q_post.pop();
        sum_post[i] = sum_post[i+1] - tmp + a[N+i];
    }
    /*
    cout << " ---------------------- " << endl;
    for(auto x:sum_pre) cout << x << " ";
    cout << endl;
    cout << " ---------------------- " << endl;
    for(auto x:sum_post) cout << x << " ";
    cout << endl;
    cout << " ---------------------- " << endl;
    */
    rep(i,0,result.size()) result[i] = sum_pre[i] - sum_post[i];
    cout << *max_element(result.begin(),result.end()) << endl;

}
