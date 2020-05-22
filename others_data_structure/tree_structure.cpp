#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 1000000000000
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)
using ipair = pair<ll,ll>;
const ll MOD = 1e9+7;

//木構造の1ノード
struct treeEdge{
    vector<ll> child;
    ll parent;
    ll depth;
};

vector<treeEdge> tree;//index iには i番目のノード情報
vector<vector<ll>> depthMat; // index i　には深さiのノードIndex
ll maxDepth;//最大深さ
void make_tree(vector<vector<ll>> E, ll N, ll root){
    tree.assign(N,{{},-1,-1});
    depthMat.assign(N,vector<ll>{});

    tree[root].depth = 0;
    depthMat[0].push_back(root);
    queue<ll> que; que.push(root);

    while(!que.empty()){
        ll top = que.front(); que.pop();
        for(ll x: E[top]){
            if(tree[x].depth!=-1) continue;            
            maxDepth = tree[top].depth+1;
            tree[top].child.push_back(x);
            tree[x].parent = top;
            tree[x].depth = maxDepth;
            depthMat[maxDepth].push_back(x);
            que.push(x);
        }
    }
}


int main(){
    ll N,tmp1,tmp2;
    cin >> N;
    vector<vector<ll>> edge(N);
    rep(i,0,N-1){
        cin >> tmp1 >> tmp2;
        edge[tmp1-1].push_back(tmp2-1);
        edge[tmp2-1].push_back(tmp1-1);
    }
    make_tree(edge,N,0);
    
    for(int i=0;i<=maxDepth;i++){
        cout << "------------------" << endl;
        cout << "depth:" << i <<endl;
        for(ll x:depthMat[i]){
            cout << "parent:" << x <<" child: ";
            for(ll y:tree[x].child) cout << y << " ";
            cout << endl;
        }
    }
}