//Atcodder Dp

#include<bits/stdc++.h>
using namespace std;
const int INF = 2*1e9;

int main(){
  int n;
  cin>>n;
  vector<vector<int>> A(n,vector<int>(3,0));
  int a,b,c;
  for(int i=0;i<n;i++){
      cin>>a>>b>>c;
      A[i] = {a,b,c};
  }
  
  vector<vector<int>> dp(n,vector<int>(3,0));
  for(int i=0;i<3;i++){
      dp[0][i] = A[0][i];
  }
  
  for(int i=1;i<n;i++){
      int elem=0;
      for(int j=0;j<3;j++){
          elem=0;
          for(int k=0;k<3;k++){
              if(k!=j)
                elem=max(elem,A[i-1][k]);
          }
          //cout<<"elem: "<<elem<<endl;
          A[i][j]+=elem;
      }
  }
//   for(int i=0;i<n;i++){
//       for(int j=0;j<3;j++){
//           cout<<A[i][j]<<" ";
//       }
//       cout<<endl;
//   }
//   cout<<endl;
  int ans=0;
  for(int j=0;j<3;j++){
      ans = max(ans,A[n-1][j]);
  }
  cout<<ans<<endl;
  return 0;
}
