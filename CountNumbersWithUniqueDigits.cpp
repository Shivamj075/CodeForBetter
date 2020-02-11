//LeetCode

class Solution {
public:
    int dp[15];
    int countNumbersWithUniqueDigits(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
    //Top Down
    int solve(int n){
        if(n==0)
            return 1;
        if(n==1)
            return 10;
        if(dp[n]!=-1)
            return dp[n];
        int f1 = solve(n-1);
        int f2 = solve(n-2);
        dp[n] = f1+ (f1-f2) *(10-n+1);
        
        return dp[n];
    }
    
    /*
    //Method 1
    int solve(int n){
        if(n==0)
            return 1;
        if(n==1)
            return 10;
        int ans = 10,base = 9;
        for(int i=2;i<=n;i++){
            base*=(9-i+2);
            ans+=base;
        }
        return ans;
    }
    */
};
