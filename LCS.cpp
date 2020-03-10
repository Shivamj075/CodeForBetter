//Atcoder DP

#include<bits/stdc++.h>
using namespace std;
void LCS(string s,string t){
    int n=s.size(),m=t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    //cout<<dp[n][m]<<endl;
    vector<char> res;
    int i=n,j=m;
    while(i>0 and j>0){
        if(s[i-1]==t[j-1]){
            res.push_back(s[i-1]);
            i--,j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    string p="";
    if(res.size()==0)
        cout<<p<<endl;
    else{
    for(int i=res.size()-1;i>=0;i--)
        cout<<res[i];
    cout<<endl;
    }
    
}
int main() {
	// your code goes here
	string s,t;
	cin>>s>>t;
	
	LCS(s,t);
	return 0;
}
