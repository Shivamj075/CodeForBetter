#define mod 10003
int Solution::solve(int A) {
    int dp[A+1];
    dp[0] = 1;
    dp[1]=1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i=4;i<=A;i++){
        dp[i] = dp[i-1] + (i-1)*dp[i-2];
        dp[i]=dp[i]%mod;
    }
    return dp[A];
}
