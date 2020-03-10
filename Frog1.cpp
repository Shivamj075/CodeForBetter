//Atcoder
#include<bits/stdc++.h>
using namespace std;
const int INF = 2*1e9;
// int recur(vector<int>&A,vector<int>&dp,int i){
//   if(i>=A.size())
//     return 0;
  
// //   if(dp[i]!=INF)
// //     return dp[i];
    
// //   if(i+1<A.size()){
// //     int cost1 = abs(A[i]-A[i+1]) + recur(A,dp,i+1);
// //     dp[i]=min(dp[i],cost1);
// // 	}
// //   if(i+2<A.size()){
// //     int cost2 = abs(A[i]-A[i+2]) + recur(A,dp,i+2);
// //     dp[i]=min(dp[i],cost2);
// //   }
  
//   return min(abs(A[i]-A[i+1]) + recur(A,dp,i+1),abs(A[i]-A[i+2]) + recur(A,dp,i+2)) ;
// }
int main(){
  int n;
  cin>>n;
  vector<int> A(n);
  int a;
  for(int i=0;i<n;i++){
    cin>>a;
    A[i]=a;
  }
  
  vector<int> dp(n,INF);
  dp[0]=0;
  for(int i=0;i<n;i++){
      for(auto j:{i+1,i+2}){
          if(j<n)
          dp[j] = min(dp[j],dp[i]+abs(A[i]-A[j]));
          
      }
    //   if(i+1<n)
    //     dp[i+1] = min(dp[i+1],dp[i]+abs(A[i]-A[i+1]));
    //   if(i+2<n)
    //     dp[i+2] = min(dp[i+2],dp[i]+abs(A[i]-A[i+2]));
  }
  
    cout<<dp[n-1]<<endl;
  return 0;
}
