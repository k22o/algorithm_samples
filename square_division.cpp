#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<functional>
#include<cmath>
#include<string>
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
#define INF  100000000
using namespace std;

//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
vector<int> initialize(vector<int> original,int sqrtSize){
    vector<int> sqrtDiv(sqrtSize,0);
    for(int i=0;i<sqrtSize;i++){
        vector<int>::iterator iter1 = original.begin()+ i*sqrtSize;        
        sqrtDiv[i] = accumulate(iter1,iter1+sqrtSize,0);
    }
    return sqrtDiv;
}

vector<int> update(vector<int> sqrtDiv,int idx, int value){            
    sqrtDiv[idx/sqrtDiv.size()] += value;
    return sqrtDiv;
}

int sqrtFind(vector<int> original,vector<int> sqrtDiv,int start, int end){
    int sqrtSize = sqrtDiv.size();
    int tmp1 = start/sqrtSize;
    int tmp2 = end/sqrtSize;
    vector<int>::iterator iter_s = original.begin()+start;
    vector<int>::iterator iter_e = original.begin()+end+1;
    vector<int>::iterator iter_d = sqrtDiv.begin();

    if(tmp1 == tmp2 && end-start+1==sqrtSize){
        return sqrtDiv[tmp1];
    }else if (tmp1==tmp2){
        return accumulate(iter_s,iter_e,0);
    }else{
        int tmp3 = accumulate(iter_s,original.begin()+(tmp1+1)*sqrtSize,0);
        int tmp4 = accumulate(original.begin()+tmp2*sqrtSize,iter_e,0);
        int tmp5;
        if(tmp1+1<=tmp2-1){
            tmp5 = accumulate(iter_d+tmp1+1,iter_d+tmp2,0);
            }
        else tmp5=0;
        return tmp3+tmp4+tmp5;
    }
}

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> com(q,0),x(q,0),y(q,0);
    rep(i,0,q){cin >> com[i] >> x[i] >> y[i];};
    int sqrtSize = (int)sqrt(n)+1;
    vector<int> original(sqrtSize*sqrtSize,0);
    vector<int> sqrtDiv = initialize(original,sqrtSize);
    rep(i,0,q){
        if(com[i]==0){
            original[x[i]-1] += y[i];
            sqrtDiv = update(sqrtDiv,x[i]-1,y[i]);
        }
        else if(com[i]==1){
            int tmp = sqrtFind(original,sqrtDiv,x[i]-1,y[i]-1);
            cout << tmp << endl;
        }
        /*
        for(auto x:original) cout << x << " ";
        cout << endl;
        for(auto x:sqrtDiv) cout << x << " ";
        cout << endl;
        */
    }
}
