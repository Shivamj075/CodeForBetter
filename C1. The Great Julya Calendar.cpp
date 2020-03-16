//Codeforces
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;
ll fast_exp(int base, int exp) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%MOD;
       base=(base*base)%MOD;
       exp/=2;
    }
    return res%MOD;
}
ll dp[1000001][10];
int digitAt(ll n,ll i){
    return (int)(n/pow(10,i))%10;
}
const ll INF = 1e9;
ll recur(ll n,int i){
    if(n==0)
        return 0;
    if(n<0)
        return INF;
    if(i>log10(n)+1)
        return INF;
    
    ll &res = dp[n][i];
    if(res!=-1)
        return res;
    res=INF;
    
    res = min(res,recur(n-digitAt(n,i),0)+1);
    res = min(res,recur(n,i+1));
    
    return res;
}
int main(){
    ll n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<recur(n,0)<<endl;
    
    return 0;
}
