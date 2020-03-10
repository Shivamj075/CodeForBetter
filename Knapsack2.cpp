//Atcoder Dp
#include<bits/stdc++.h>
using namespace std;
const int INF = 2*1e9;
#define ll long long
// ll knapsack(vector<pair<ll,ll>>&A,vector<vector<ll>>&dp,ll i,ll totalWeight){
//     if(i>=A.size())
//         return 0;
//     if(dp[i][totalWeight]!=-1)
//         return dp[i][totalWeight];
//     ll itemWt = A[i].first;
//     ll itemVa = A[i].second;
    
//     if(itemWt<=totalWeight){
//         ll cost1  = itemVa+knapsack(A,dp,i+1,totalWeight-itemWt);
//         ll cost2 = knapsack(A,dp,i+1,totalWeight);
        
//         dp[i][totalWeight] = max(cost1,cost2);
//     }
//     else
//         return dp[i][totalWeight] = knapsack(A,dp,i+1,totalWeight);
//     return dp[i][totalWeight];
     
// }
int main(){
  ll n,w;
  cin>>n>>w;
  vector<pair<ll,ll>> A(n);
  ll val,wt,V;
  for(ll i=0;i<n;i++){
      cin>>wt>>val;
      A[i]={wt,val};
      V+=val;
  }
  
  //vector<vector<ll>> dp(n,vector<ll>(w+1,-1));
  vector<ll> dp(n*1000+1,INF);
  dp[0]=0;
  for(int i=0;i<n;i++){
      ll itemVa=A[i].second,itemWt=A[i].first;
      for(int j=V;j>=itemVa;j--){
          dp[j] = min(dp[j],dp[j-itemVa]+itemWt);
      }
  }
  for(int i=V;i>=0;i--){
      if(dp[i]<=w){
          cout<<i<<endl;
          break;
      }
  }
  //cout<<knapsack(A,dp,0,w)<<endl;
  return 0;
}
