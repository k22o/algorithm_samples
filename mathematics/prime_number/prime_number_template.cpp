#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using namespace std;
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ipair = std::pair<ll,ll>;


//素数判定
bool prime_number(int a){
    int flag = true;
    for(int i=2;i<sqrt(a)+1;i++){
        if(a%i==0){flag=false;break;}
    }
    return flag;
}

int main(){
    int N;
    cin >> N;
    bool prime = prime_number(N);
    if(prime) cout << "YES" << endl;
    else cout << "NO" << endl;

}