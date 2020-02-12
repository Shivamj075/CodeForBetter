//LeetCode

/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.

*/

class Solution {
public:
    
    int dp[100][5010];
    int findTargetSumWays(vector<int>& nums, int S) {
        
        if(abs(S)>1000) return 0;
    int n=nums.size();
    memset(dp,-1,sizeof(dp));
    int ans=solve(nums,n,S);
    return ans;
    }
    
    
    int solve(vector<int>nums,int n,int s){
        
        if(n==0)
    {
        if(s==0) return 1;
        else return 0;
    }
    if(dp[n][s+2000]!=-1)
      return dp[n][s+2000];
    
    return dp[n][s+2000]=solve(nums,n-1,s-nums[n-1])+solve(nums,n-1,s+nums[n-1]);
        
    }
};
