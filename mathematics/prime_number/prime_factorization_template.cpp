#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using namespace std;
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ipair = std::pair<int,int>;


//素因数分解
//素因数分解した全ての数を返す
vector<int> prime_factorization(int a){
    if(a<=0) return {0};
    if(a==1) return {1};
    vector<int> ans;
    int num = a;
    for(int i=2;i<=a;i++){
        while(num%i ==0){
            ans.push_back(i);
            num = num/i;
        }
        if(num==1) break;
    }
    return ans;
}

//素因数分解で求まった素数を返す
set<int> prime_factorization2(int a){
    if(a<=0) return {0};
    if(a==1) return {1};
    vector<int> ans;
    int num = a;
    for(int i=2;i<=a;i++){
        while(num%i ==0){
            ans.push_back(i);
            num = num/i;
        }
        if(num==1) break;
    }
    set<int> s(ans.begin(),ans.end());
    return s;
}

//素因数分解の素因数の数を返す
vector<int> prime_factorization3(int a){
    if(a<=0) return {0};
    if(a==1) return {1};
    vector<int> ans;
    int num = a;
    for(int i=2;i<=a;i++){
        while(num%i ==0){
            ans.push_back(i);
            num = num/i;
        }
        if(num==1) break;
    }
    set<int> s(ans.begin(),ans.end());
    vector<int> cnt(s.size(),0);
    auto itr = s.begin();
    rep(i,0,cnt.size()) {
        cnt[i] = count(ans.begin(),ans.end(),*itr);
        itr++;
    }
    return cnt;
}

int main(){
    int N;
    cin >> N;
    vector<int> ans1 = prime_factorization(N);
    set<int> ans2 = prime_factorization2(N);
    vector<int> ans3 = prime_factorization3(N);

    for(auto x:ans1) cout << x << " ";
    cout << endl;
    for(auto x:ans2) cout << x << " ";
    cout << endl;
    for(auto x:ans3) cout << x << " ";
    cout << endl;

}