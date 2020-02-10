//LeetCode

class Solution {
public:
    int rob(vector<int>& nums) {
        size_t n = nums.size();
        if(n == 0)
            return 0;
        else if(n == 1)
            return nums[0];
        
        int best_so_far = nums[0];
        int minus_two = 0;
        
        for(int i = 1; i < n - 1; ++i) {
            int tmp = best_so_far;
            best_so_far = max(best_so_far, minus_two + nums[i]);
            minus_two = tmp;
        }
            
        int new_best_so_far = nums[1];
        minus_two = 0;
        for(int i = 2; i < n; ++i) {
            int tmp = new_best_so_far;
            new_best_so_far = max(new_best_so_far, minus_two + nums[i]);
            minus_two = tmp;
        }
        
        return max(best_so_far, new_best_so_far);
    }
    
//     int solve(vector<int>&A,int i,int j){ 
//         vector<int> dp(A.size()+1,0);
//         dp[i] = A[i];
//         dp[i+1] = max(A[i],A[i+1]);
        
//         for(int k=i+2;k<j;k++){
//             dp[k] = max(A[k]+dp[k-2],dp[k-1]);
//         }
        
//         return dp[j];
//     }
};
