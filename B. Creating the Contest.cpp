//CodeForces
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

int main(){
    int n;
    cin>>n;
    vector<int>A(n);
    int ans=1;
    for(int i=0;i<n;i++)
        cin>>A[i];
    vector<int> dp(n,1);
    for(int i=1;i<n;i++){
        if(A[i]<=2*A[i-1])
            dp[i]=1+dp[i-1];
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    
}
