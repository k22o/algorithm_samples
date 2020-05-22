#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<functional>
using namespace std;

int main(){

    //2分探索によって，目的の変数のインデックスを返す
    vector<int> a = {1,5,3,2,2};
    sort(a.begin(),a.end());
    int key = 3;
    
    //key以上の値のイテレータを返す
    //ソートしておけば，key以上の最小の値のイテレータが求まる
    auto iter = lower_bound(a.begin(),a.end(),key);
    if(iter !=a.end() && *iter == key){
        cout << key << " found " << distance(a.begin(), iter) << endl;        
    }else{
        cout << key << " not found " << endl;
    }
    return 0;
}
