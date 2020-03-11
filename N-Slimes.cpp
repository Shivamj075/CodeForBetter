///Atcoder dp 

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
const ll INF = 1e18L + 5;

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
   vector<ll> A(n);
   for(int i=0;i<n;i++)
    cin>>A[i];
    int N=n;
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,INF));
    
    for(int L=N-1;L>=0;L--){
        for(int R=L;R<n;R++){
            if(L==R)
                dp[L][R]=0;
            else{
                ll sum=0;
                for(int i=L;i<=R;i++)
                    sum+=A[i];
                for(int k=L;k<=R-1;k++){
                    dp[L][R] = min(dp[L][R],dp[L][k]+dp[k+1][R]+sum);
                }
            }
        }
    }
    
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    cout<<dp[0][n-1]<<endl;
    
}
