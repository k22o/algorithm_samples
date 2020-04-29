#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)

int operate(int bit, int dig, int n1, int n2){
    if(bit & (1<< dig)) return n1+n2;
    else return n1-n2;    
}

char operate_c(int bit, int dig){
    if(bit & (1<< dig)) return '+';
    else return '-';    
}

//https://atcoder.jp/contests/abc079/tasks/abc079_c
int main(){
    int N,A,B,C,D,sum;
    cin >> N;
    A = N /1000;
    B = (N-A*1000)/100;
    C = (N-A*1000-B*100)/10;
    D = N%10;
    for(int bit = 0;bit <(1<<3);bit++){
        sum = A;
        sum = operate(bit,0,sum,B);
        sum = operate(bit,1,sum,C);
        sum = operate(bit,2,sum,D);      
        if(sum==7){
            cout << A << operate_c(bit,0) << B << operate_c(bit,1) << C <<operate_c(bit,2) << D <<"=7" << endl;
            break;
        }
    }
}