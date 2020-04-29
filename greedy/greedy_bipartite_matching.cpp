#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)

//https://atcoder.jp/contests/abc091/tasks/arc092_a
int main(){
    int N;
    cin >> N;
    vector<pair<int,int>>red(N,make_pair(0,0)),blue(N,make_pair(0,0));
    rep(i,0,N) cin >>red[i].first >> red[i].second;    
    rep(i,0,N) cin >>blue[i].second >> blue[i].first;        
    sort(red.begin(),red.end(),less<pair<int,int>>());
    sort(blue.begin(),blue.end(),less<pair<int,int>>());
    vector<int> exclude;
    rep(i,0,N){
        rep(j,0,N){
            if(red[j].first<blue[i].second && red[j].second<blue[i].first && find(exclude.begin(),exclude.end(),j)==exclude.end()){
            cout << red[i].first << " " << red[i].second << " " << blue[j].first << " "<< blue[j].second << endl; 
                exclude.push_back(j);
                break;
            }
        }
    }
    cout << exclude.size() << endl;
}
