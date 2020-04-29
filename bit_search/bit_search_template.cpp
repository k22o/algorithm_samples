#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 100000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)

int main(){
    int N = 5;
    //0からn-1までの部分集合の全探索
    // 2^N通りを実現
    for(int bit = 0;bit <(1<<N);bit++){//bitのN番目に1が立つまで増やす
        vector<int> S;
        rep(i,0,N){
            if(bit & (1<<i)){//iがbitに入っているか　※ 0<<iは使えない！！
                S.push_back(i);
            }
        }
        cout << bit << ": {";
        for (int i = 0; i < (int)S.size(); ++i) {
            cout << S[i] << " ";
        }
        cout << "}" << endl;

    }
}