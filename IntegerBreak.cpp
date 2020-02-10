//LeetCode

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
    
    int solve(int n,vector<int>&dp){
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        if(n<=4)
            return n;
        if(dp[n]!=-1)
            return dp[n];
        int res=(n/2)*(n-n/2);
        for(int i=1;i<n;i++){
            res = max(res,i*solve(n-i,dp));
        }
        dp[n] = res;
        return res;
    }
    /*
    //BottomUp
    int solve(int n,vector<int> &dp){
        
        dp[0]=0,dp[1]=0;
        dp[2]=1;
        for(int i=3;i<=n;i++){
            for(int j=1;j<i;j++){
                dp[i]=max(dp[i],max(j*(i-j),j*dp[i-j]));
            }
        }
        
        return dp[n];
    }*/
};
