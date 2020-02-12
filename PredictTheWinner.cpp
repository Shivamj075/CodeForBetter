//LeetCode

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size()==1)
            return 1;
        int turn=0;
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int p1 = solve(nums,dp,0,n-1);
        int total=0;
        for(int i=0;i<n;i++)
            total+=nums[i];
        int p2 = total-p1;
        
        return p1>=p2;
    }
    
    /*
    //BruteForce
    bool solve(vector<int>&nums,int s,int e,int p1,int p2,int turn){
        if(s>e){
            return p1>=p2?1:0;
        }
        
        if(turn%2==0){
            return solve(nums,s+1,e,p1+nums[s],p2,turn+1)||solve(nums,s,e-1,p1+nums[e],p2,turn+1);
        }
        else{
            return solve(nums,s+1,e,p1,p2+nums[s],turn+1)&&solve(nums,s,e-1,p1,p2+nums[e],turn+1);
        }
    }
    */
    
    int solve(vector<int>&A,vector<vector<int>> &dp,int s,int e){
        if(s>e){
            return 0;
        }
        
        if(dp[s][e]!=-1)
            return dp[s][e];
        
        return dp[s][e] = max(A[s]+min(solve(A,dp,s+2,e),solve(A,dp,s+1,e-1)),A[e]+min(solve(A,dp,s,e-2),solve(A,dp,s+1,e-1)));
        
    }
};
