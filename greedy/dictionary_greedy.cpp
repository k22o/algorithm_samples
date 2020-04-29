#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)

//https://atcoder.jp/contests/abc076/tasks/abc076_c
int main(){
    string Sp,T;
    bool flag;
    vector<string> S;
    cin >> Sp >> T;
    rep(i,0,Sp.size()-T.size()+1){
        flag = true;
        rep(j,0,T.size()){
            if(Sp[i+j] !='?' &&  Sp[i+j] != T[j]){
                flag = false;
                break;
            }
        }
        if(flag){
            string tmpS = Sp;
            for(int j=0;j<T.size();j++) tmpS[i+j] = T[j];
            S.push_back(tmpS);
        } 
    } 
    if(S.size()!=0){
        rep(i,0,S.size()){rep(j,0,S[i].size()) if(S[i][j]=='?') S[i][j]='a';} 
        sort(S.begin(),S.end());
        cout << S[0] << endl;
    }
    else cout << "UNRESTORABLE" << endl;
}