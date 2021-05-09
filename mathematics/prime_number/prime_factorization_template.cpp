#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using namespace std;
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)
using ipair = std::pair<ll,ll>;


//素因数分解
//素因数分解した全ての数を返す
vector<ll> prime_factorization(ll a){
    if(a<=0) return {0};
    if(a==1) return {1};
    vector<ll> ans;
    ll num = a;
    for(ll i=2;i<=sqrt(a)+1;i++){
        while(num%i ==0){
            ans.push_back(i);
            num = num/i;
        }
        if(num==1) break;
    }
    if(num!=1) ans.push_back(num);
    return ans;
}

//素因数分解で求まった素数を返す
set<ll> prime_factorization2(ll a){
    if(a<=0) return {0};
    if(a==1) return {1};
    vector<ll> ans;
    ll num = a;
    for(ll i=2;i<=sqrt(a)+1;i++){
        while(num%i ==0){
            ans.push_back(i);
            num = num/i;
        }
        if(num==1) break;
    }
    if(num!=1) ans.push_back(num);
    set<ll> s(ans.begin(),ans.end());
    return s;
}

//素因数分解の素因数の数を返す
vector<ll> prime_factorization3(ll a){
    if(a<=0) return {0};
    if(a==1) return {1};

    vector<ll> ans;
    ll num = a;
    for(ll i=2;i<=sqrt(a)+1;i++){
        while(num%i ==0){
            ans.push_back(i);
            num = num/i;
        }
        if(num==1) break;
    }
    if(num!=1) ans.push_back(num);
    set<ll> s(ans.begin(),ans.end());
    vector<ll> cnt(s.size(),0);
    auto itr = s.begin();
    rep(i,0,cnt.size()) {
        cnt[i] = count(ans.begin(),ans.end(),*itr);
        itr++;
    }
    return cnt;
}


int main(){
    ll N;
    cin >> N;
    vector<ll> ans1 = prime_factorization(N);
    set<ll> ans2 = prime_factorization2(N);
    vector<ll> ans3 = prime_factorization3(N);

    for(auto x:ans1) cout << x << " ";
    cout << endl;
    for(auto x:ans2) cout << x << " ";
    cout << endl;
    for(auto x:ans3) cout << x << " ";
    cout << endl;

}