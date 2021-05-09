#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ipair = pair<int,int>;
#define INF 2000000000

//https://atcoder.jp/contests/abc170/tasks/abc170_e

int main(){
    int N,Q;
    cin >> N >> Q;
    vector<int>A(N,0),B(N,0); 
    rep(i,0,N) cin >> A[i] >>B[i]; 
    transform(B.begin(),B.end(),B.begin(),[](int x){return x-1;}); 

    vector<int> stay(N,0); 
    vector<multiset<ipair>> school(200001);
    multiset<ipair> maxArr;

    //itinalization
    rep(i,0,N){
        stay[i] = B[i];
        school[B[i]].insert(make_pair(A[i],i));
    }

    rep(i,0,school.size()){
        if(school[i].size()!=0) maxArr.insert(*(--school[i].end()));
    }

    vector<ll> ans(Q,INF);
    int c,d;
    rep(i,0,Q){
        cin >> c >> d; c--; d--;
        ipair findKey = make_pair(A[c],c);
        if(*(--school[stay[c]].end())==findKey){
            school[stay[c]].erase(findKey);
            maxArr.erase(findKey);
            if(school[stay[c]].size()!=0)maxArr.insert(*(--school[stay[c]].end()));
        }else{
            school[stay[c]].erase(findKey);
        }
        stay[c] = d;
        if(school[d].size()==0){
            school[d].insert(findKey);
            maxArr.insert(findKey);
        }else if(*(--school[d].end()) < findKey){
            maxArr.erase(*(--school[d].end()));
            maxArr.insert(findKey);
            school[d].insert(findKey);
        }else{
            school[d].insert(findKey);
        }
        ans[i] = (*(maxArr.begin())).first;
    }
    for(auto x:ans) cout << x << endl;
}
