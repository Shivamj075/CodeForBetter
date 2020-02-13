//LeetCode

#define mod 1000000007
class Solution {
public:
    
    int findPaths(int m, int n, int N, int i, int j) {
        
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(N+1,-1)));
        return solve(dp,m,n,i,j,N);
    }
    
    int solve(vector<vector<vector<int>>> &dp,int m,int n,int i,int j,int N){
        if(i>=m or j>=n or i<0 or j<0)
            return 1;
        if(N<=0)
            return 0;
        
        if(dp[i][j][N]!=-1)
            return dp[i][j][N]%mod;
        int res1,res2;
        res1 = (solve(dp,m,n,i-1,j,N-1)%mod + solve(dp,m,n,i,j-1,N-1)%mod)%mod;
        res2 =  (solve(dp,m,n,i+1,j,N-1)%mod + solve(dp,m,n,i,j+1,N-1)%mod)%mod;
        
        dp[i][j][N] = (res1%mod+res2%mod)%mod;
        return dp[i][j][N];
        
    }
};
