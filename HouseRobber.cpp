class Solution {
public:
    //int dp[100100];
    int rob(vector<int>& nums) {
       
        int n=nums.size();
        vector<int> dp(n+1);
        if(n<2) return n?nums[0]:0;
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[n-1];
    }
    
//     int solve(vector<int>&A,int i){
//         if(i>=A.size())
//             return 0;
        
//         if(dp[i]!=0)
//             return dp[i];
//         dp[i] = max(A[i]+solve(A,i+2),solve(A,i+1));
        
//         return dp[i];
//     }
};
