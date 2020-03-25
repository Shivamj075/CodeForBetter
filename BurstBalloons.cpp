class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int> A(n+2,1);
        int indx=1;
        for(auto x:nums){
            A[indx++] = x;
        }
        n=A.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        return topdown(A,dp,0,n-1);
    }
    
    int topdown(vector<int>&A,vector<vector<int>>&dp,int left,int right){
        if(left+1==right)
            return 0;
        if(dp[left][right]>0)
            return dp[left][right];
        
        int ans = 0;
        for(int i=left+1;i<right;i++){
            dp[left][right] =max(dp[left][right],A[left]*A[i]*A[right]+topdown(A,dp,left,i)+topdown(A,dp,i,right));
            
        }
        //dp[left][right]=ans;
        return dp[left][right];
    }
};
