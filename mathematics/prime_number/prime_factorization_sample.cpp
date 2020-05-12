#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using namespace std;
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)
using ipair = std::pair<ll,ll>;


//素因数分解
vector<ll> prime_factorization(ll a){
    if(a<=0) return {0};
    if(a==1) return {1};
    vector<ll> ans;
    ll num = a;
    for(ll i=2;i<=a;i++){
        while(num%i ==0){
            ans.push_back(i);
            num = num/i;
        }
        if(num==1) break;
    }
    return ans;
}

//https://atcoder.jp/contests/abc052/tasks/arc067_a
int main(){
    ll N,ans=1;
    cin >> N;

    vector<vector<ll>> vec(N+1);
    set<ll> s;
    rep(i,2,N+1){
        vec[i] = prime_factorization(i);
        set<ll> tmp (vec[i].begin(),vec[i].end());
        auto itr = tmp.begin();
        rep(i,0,tmp.size()){
            s.insert(*itr);
            itr++;
        }
    }
    vector<ll> cnt(s.size(),0);
    rep(i,2,N+1){
        auto itr = s.begin();
        rep(j,0,s.size()){
            cnt[j] += count(vec[i].begin(),vec[i].end(),*itr);
            itr++;
        }
    }
    /*for(auto x:s) cout << x << " ";
    cout << endl;
    for(auto x:cnt) cout << x << " ";
    cout << endl;*/

    rep(i,0,s.size()) ans = (ans * (cnt[i]+1))%((ll)1e9 +7);
    cout << ans % ((ll)1e9 +7) << endl;
}