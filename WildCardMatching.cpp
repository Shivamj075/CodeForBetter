//LeetCode

class Solution {
public:
     
    bool isMatch(string s, string p) {
        
        //int n = s.size(),m = p.size();
        int m=p.size(),n=s.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    dp[0][0]=1;
    for(int i=1;i<=m;i++){
        dp[i][0] = p[i-1]=='*' && dp[i-1][0];
    }
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1]==p[i-1] or p[i-1]=='?')
                dp[i][j] = dp[i-1][j-1];
            else if(p[i-1]=='*')
                dp[i][j] = dp[i-1][j] or dp[i][j-1];
        }
    }
    
    return dp[m][n];
    }
    
   
};
