#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using namespace std;
#define INF 100000000
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)


//https://atcoder.jp/contests/dwacon2018-prelims/tasks/dwacon2018_prelims_c
const ll MOD = 1e9+7;
vector<vector<ll>> partition(ll n, ll k){
    vector<vector<ll>> P(n+1,vector<ll>(k+1,0));
    rep(j,0,k+1) P[0][j] = 1;
    rep(i,1,n+1){
        rep(j,1,k+1){
            P[i][j] = (P[i][j-1] + (i-j>=0 ? P[i-j][j] : 0))%MOD;
        }
    }
    return P;
}

int main() {
    ll N,M,sumA,sumB,pre;
    cin >> N >> M;
    vector<ll> A(N,0); 
    vector<ll> B(M,0);
    rep(i,0,N) cin >> A[i];
    rep(i,0,M) cin >> B[i];
    sumA = accumulate(A.begin(),A.end(),0LL);
    sumB = accumulate(B.begin(),B.end(),0LL);
    vector<vector<ll>> PA = partition(sumB,N);
    vector<vector<ll>> PB = partition(sumA,M);

    vector<ll> Acnt,Bcnt;
    pre = A[0]; Acnt.push_back(1);
    rep(i,1,N){
        if (pre==A[i]) Acnt[Acnt.size()-1] ++;
        else Acnt.push_back(1);
        pre  = A[i];
    }
    pre = B[0]; Bcnt.push_back(1);
    rep(i,1,M){
        if (pre==B[i]) Bcnt[Bcnt.size()-1] ++;
        else Bcnt.push_back(1);
        pre  = B[i];
    }
    //cout << Acnt.size() << Bcnt.size() << endl;
    vector<vector<ll>> dpA(sumB+1,vector<ll>(Acnt.size()+1,0));
    rep(i,0,dpA[0].size())dpA[0][i] = 1;
    rep(i,1,sumB+1){
        rep(j,1,Acnt.size()+1){
            rep(k,0,sumB+1){
                if(i-k>=0){dpA[i][j] = (dpA[i][j] + dpA[i-k][j-1]*PA[k][Acnt[j-1]]%MOD)%MOD;
                }
            }
        }
    }
   vector<vector<ll>> dpB(sumA+1,vector<ll>(Bcnt.size()+1,0));
    rep(i,0,dpB[0].size())dpB[0][i] = 1;
    rep(i,1,sumA+1){
        rep(j,1,Bcnt.size()+1){
            rep(k,0,sumA+1){
                if(i-k>=0)dpB[i][j] = (dpB[i][j] + dpB[i-k][j-1]*PB[k][Bcnt[j-1]]%MOD)%MOD;
            }
        }
    }
    cout << dpA[sumB][Acnt.size()]*dpB[sumA][Bcnt.size()]%MOD << endl;

}