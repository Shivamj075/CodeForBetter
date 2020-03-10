#include<bits/stdc++.h>
using namespace std;
const int INF = 2*1e9;
#define ll long long
ll knapsack(vector<pair<ll,ll>>&A,vector<vector<ll>>&dp,ll i,ll totalWeight){
    if(i>=A.size())
        return 0;
    if(dp[i][totalWeight]!=-1)
        return dp[i][totalWeight];
    ll itemWt = A[i].first;
    ll itemVa = A[i].second;
    
    if(itemWt<=totalWeight){
        ll cost1  = itemVa+knapsack(A,dp,i+1,totalWeight-itemWt);
        ll cost2 = knapsack(A,dp,i+1,totalWeight);
        
        dp[i][totalWeight] = max(cost1,cost2);
    }
    else
        return dp[i][totalWeight] = knapsack(A,dp,i+1,totalWeight);
    return dp[i][totalWeight];
     
}
int main(){
  ll n,w;
  cin>>n>>w;
  vector<pair<ll,ll>> A(n);
  ll val,wt;
  for(ll i=0;i<n;i++){
      cin>>wt>>val;
      A[i]={wt,val};
  }
  
  vector<vector<ll>> dp(n,vector<ll>(w+1,-1));
  
  cout<<knapsack(A,dp,0,w)<<endl;
  return 0;
}
