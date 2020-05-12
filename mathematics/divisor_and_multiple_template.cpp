#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 1000000000000000LL
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ipair = std::pair<ll,ll>;

//最大公約数
int gcd(int a, int b){
    int tmp;
    if(a<b){
        tmp = a;
        a = b;
        b = tmp;
    }
    if(b==0) return a;
    else return gcd(b, a%b);
}

//最小公倍数
int lcm(int a, int b){
    return a*b/gcd(a,b);
}

//約数列挙
set<int> divisor(int a){
    vector<int> tmp;
    for(int i=1;i<(int)sqrt(a)+1;i++){
        if (a%i==0){
            tmp.push_back(i);
            tmp.push_back(a/i);
        }
    }
    set<int> ans (tmp.begin(),tmp.end());
    return ans;
}


int main(){
    int n;
    cin >> n;
    set<int> ans = divisor(n);
    for(auto x:ans) cout << x << endl;
}