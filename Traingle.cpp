//LeetCode

class Solution {
public:
    int minimumTotal(vector<vector<int>>& A) {
        
        vector<vector<int>> dp = A;
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[i].size();j++){
                dp[i][j]=-1;
            }
        }
        int ans=0;
        return solve(A,dp,0,0,ans);
    }
    
    int solve(vector<vector<int>>& A,vector<vector<int>>& dp,int i,int j,int &ans){
        if(i>=A.size() or j>=A[i].size())
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        dp[i][j]=A[i][j]+min(solve(A,dp,i+1,j,ans),solve(A,dp,i+1,j+1,ans));
        
        return dp[i][j];
    }
};
