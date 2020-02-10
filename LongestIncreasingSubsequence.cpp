//LeetCode

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n+1,1);
        if(nums.size()==0)
            return 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
        }
        int ans = 1;
        for(int i=0;i<=n;i++){
            //cout<<dp[i]<<" ";
            ans=max(ans,dp[i]);
        }
       // cout<<endl;
        return ans;
    }
};
