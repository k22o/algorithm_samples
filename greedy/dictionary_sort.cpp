#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ll = long long int;
using ipair = pair<int,int>;

/*
辞書順
*/

//http://poj.org/problem?id=3617
int main(){

    string str, rev_str, ans="";
    cin >> str;
    
    while(str!="") {
        rev_str = str;
        reverse(rev_str.begin(),rev_str.end());

        if(str < rev_str) {
            ans.push_back(str[0]);
            rev_str.pop_back();
            str = rev_str;
            reverse(rev_str.begin(),rev_str.end());
        }
        else {
            ans.push_back(rev_str[0]);
            str.pop_back();
        }
    }    
    cout << ans << endl;

}
