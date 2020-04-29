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

//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp
vector<int> update(vector<int> segTree,int idx, int value){            
    idx  = idx + (segTree.size()-1)/2;
    segTree[idx] = value;
    while(idx>0){
        idx = (idx-1)/2;
        segTree[idx] = min(segTree[idx*2+1],segTree[idx*2+2]);
    }
    return segTree;
}

int segFind(vector<int> segTree,int start, int end,int k,int l,int r){
    // [start-end)の区間
    // ノードk(区間[l,r)が答える)
    if(r<=start||end<=l) return INF;
    else if(start<=l && end>=r) return segTree[k];
    else{
        int c1 = segFind(segTree,start,end,2*k+1,l,(l+r)/2);
        int c2 = segFind(segTree,start,end,2*k+2,(l+r)/2,r);
        return min(c1,c2);
    }
}

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> com(q,0),x(q,0),y(q,0);
    rep(i,0,q){cin >> com[i] >> x[i] >> y[i];};
    int last_node=1;
    while(last_node<n) last_node *=2;//最後の子ノードの数
    vector<int> segTree(last_node*2-1,INF);//ノードの初期化
    rep(i,0,q){
        if(com[i]==0){
            segTree = update(segTree,x[i],y[i]);
        }
        else if(com[i]==1){
            int tmp = segFind(segTree,x[i],y[i]+1,0,0,last_node);
            cout << tmp << endl;
        }
    }
}