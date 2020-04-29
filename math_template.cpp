#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<functional>
#include<cmath>
using namespace std;

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

//階乗
int factral(int a){
    if(a==0) return 1;
    if(a==1) return 1;
    else return a*factral(a-1);
}

//順列
int permutation(int n, int k){
    if (n<k) return 0;
    return factral(n)/factral(n-k);
}

//組み合わせ
int combination(int n, int k){
    if (n<k) return 0;
    return factral(n)/(factral(k)*factral(n-k));
}

//素因数分解
vector<int> prime_factorization(int a){
    vector<int> ans;
    int num = a;
    for(int i=2;i<=(int)sqrt(a);i++){
        while(num%i ==0){
            ans.push_back(i);
            num = num/i;
        }
    }
    return ans;
}

//素数判定
bool prime_number(int a){
    int flag = true;
    for(int i=2;i<sqrt(a)+1;i++){
        if(a%2==0){flag=false;break;}
    }
    return flag;
}


int main(){
    vector<int>ans;
    ans = prime_factorization(36);
    for(auto x:ans) cout << x << " ";
    cout << endl;
}