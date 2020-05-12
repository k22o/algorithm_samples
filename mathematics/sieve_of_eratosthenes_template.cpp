#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using namespace std;
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using ipair = std::pair<int,int>;

//https://atcoder.jp/contests/tenka1-2012-qualc/tasks/tenka1_2012_9
//エラトステネスの篩
//Nまでの素数を探す
vector<int> prime_list (int N){
    //-1:未訪問 0:素数でない 1:素数
    vector<int> ans;
    vector<int> check(N+1,-1);
    rep(i,2,N+1){
        if(check[i]==-1){
            check[i]=1;
            ans.push_back(i);
            int tmp=i+i;
            while(tmp<=N){
                check[tmp] = 0;
                tmp +=i;
            }
        }        
    }
    return ans;
}

int prime_num (int N){
    //-1:未訪問 0:素数でない 1:素数
    vector<int> check(N+1,-1);
    rep(i,2,N+1){
        if(check[i]==-1){
            check[i]=1;
            int tmp=i+i;
            while(tmp<=N){
                check[tmp] = 0;
                tmp +=i;
            }
        }        
    }
    return count(check.begin(),check.end(),1);
}

int main(){
    int N;
    cin >> N;
    vector<int> pVec = prime_list(N-1);
    int pNum = prime_num(N-1);
    for(auto x:pVec) cout << x <<" ";
    cout << endl;
    cout << pNum << endl;
}