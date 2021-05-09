#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define INF 10000000
#define rep(i,a,b) for(int (i)=a;(i)<(int)(b);(i)++)
using itpl = tuple<int,int>;


class SquareDivision{
    private :
        vector<ll> data,sqData;
        ll N,sqSize,sqNum;

    public:
        SquareDivision(ll n,ll initD=0, ll initSD=0){
            this-> N = n;
            this-> sqSize = int(sqrt((double(this->N))));
            if(this->sqSize*this->sqSize != this->N) sqSize ++;
            this-> sqNum = N/sqSize + ((N%sqSize==0) ? 0 :1); 
            this->data.assign(this->N,initD);            
            this->sqData.assign(this->sqNum,initSD);
        };
    
    //IDX a add x
    void add(ll a, ll x){
        this->data[a] =this-> data[a] + x;
        ll idx = a/this->sqSize;
        this->sqData[idx] = this-> data[idx] + x;
    };

    //[a,b)
    ll getSum(ll a, ll b){
        ll sum=0;
        ll a_sq = a/this->sqSize;
        ll b_sq = b/this->sqSize;
        
        if (a_sq>b_sq) return 0;
        if (b-a <= this->sqSize){
            sum = accumulate(this->data.begin()+a,this->data.begin()+b,0LL);
            return sum;
        }

        ll idx1 = a;
        while(idx1%this->sqSize !=0){
            sum = sum + this->data[idx1];
            idx1 = idx1 +1;
        }

        ll idx2 = b;
        while(idx2%this->sqSize != 0){
            sum = sum + this->data[idx2-1];
            idx2 = idx2 -1;
        }

        idx1 = idx1/this->sqSize;
        idx2 = idx2/this->sqSize;
        for(ll i=idx1;i<idx2;i++) sum += this->sqData[i];
        return sum;
    };

    vector<ll> get_data(){return this->data;};
    vector<ll> get_sqData(){return this->sqData;};
};

int main(){
    ll n,q,com,x,y;
    vector<ll>ans,data;
    cin >> n >> q;
    SquareDivision sq(n);
    rep(i,0,q){
        cin >> com >> x >> y;
        if(com==0) sq.add(x-1,y);
        else ans.push_back(sq.getSum(x-1,y));
    }

    /*
    data = sq.get_data();
    for(auto x:data) cout << x <<" ";
    cout << endl;
    data = sq.get_sqData();
    for(auto x:data) cout << x << " ";
    cout << endl;
    */
    for(auto x:ans) cout << x << endl;
}
