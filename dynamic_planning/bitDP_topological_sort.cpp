#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000
#define rep(i,a,b) for(ll (i)=a;(i)<(ll)(b);(i)++)


//https://atcoder.jp/contests/abc041/tasks/abc041_d
//もっと良い書き方はあると思う…

//ワーシャルフロイドで現状の繋がりが分かる部分を探る
vector<ll> u,v,w;
vector<vector<ll>> dist;
void warshall_floyd(ll V){
    for(ll i=0;i<V;i++) dist[i][i] = 0;
    for(ll i=0;i<u.size();i++){
        dist[u[i]][v[i]] = w[i];       
    }
    for(ll k=0;k<V;k++){
        for(ll i=0;i<V;i++){
            for( ll j=0;j<V;j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }  
}

int main(){
    ll N,M;
    cin >> N >> M;
    u.assign(M,0);v.assign(M,0);w.assign(M,1);
    dist.assign(N,vector<ll>(N,INF));
    rep(i,0,M) cin >> u[i] >> v[i];
    transform(u.begin(),u.end(),u.begin(),[](ll x){return x-1;});
    transform(v.begin(),v.end(),v.begin(),[](ll x){return x-1;});
    warshall_floyd(N);

    vector<ll> dp((1<<N),0);
    dp[0]=1;
    for (ll bit=1; bit<(1<<N);bit++){//各点集合Sについてdpする
        for (ll i=N-1;i>=0;i--){
            if(bit & (1 << i)){//1が立っているノードに関して
                ll tmp = bit;
                tmp &= ~(1<<i);//選んだ1点以外のSのノード
                bool flag = true;
                //ルートが存在する or 未確定である ならdpを更新．
                //dist[i][j]==INF　&& dist[i][j]!=INF 向きが逆 なので×
                //dist[i][j]==INF　&& dist[i][j]==INF ルート未確定 なので〇
                //dist[i][j]!=INF  〇
                for(ll j=0;j<N;j++){
                    if(tmp&(1<<j)){
                        if(dist[i][j]==INF && dist[j][i] !=INF){flag=false;break;};
                    } 
                }
                if(flag) dp[bit] =  dp[bit] + dp[tmp];
            }
        }
    }
    cout << dp[(1<<N)-1] << endl;
}