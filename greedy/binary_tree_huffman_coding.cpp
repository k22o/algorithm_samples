#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
//http://poj.org/problem?id=3253
int main(){
    int N,tmp,top1,top2,cost=0;
    cin >> N;
    priority_queue<int,vector<int>,greater<int>> q;
    rep(i,0,N){cin >> tmp;q.push(tmp);}
    
    while(q.size()>1){
        top1 = q.top();
        q.pop();
        top2 = q.top();
        q.pop();
        q.push(top1+top2);
        cost += top1+top2;
        cout << top1 << " " << top2 << " " << cost << endl;
    }
    cout << cost << endl;

}
