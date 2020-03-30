class Solution {
public:
    const int mod = 1e9+7;
    
   int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>>dp(d + 1, vector<int>(target + 1, -1));
        return dfs(dp, d, f, target, 0, 0);
    }
    int dfs(vector<vector<int>>&dp, int d, int f, int target, int cur_d, int cur_sum) {
        if(cur_d == d && cur_sum == target) {
            return 1;
        }
        if(cur_d == d || cur_sum > target) {
            return 0;
        }
        if(dp[cur_d][cur_sum] != -1) {
            return dp[cur_d][cur_sum];
        }
        int ans = 0;
        for(int i = 1; i <= f; i++) {
            ans = (ans + dfs(dp, d, f, target, cur_d + 1, cur_sum + i) % mod) % mod;
        }
        dp[cur_d][cur_sum] = ans;
        return ans;
        
    }

//     /*
//     public int numRollsToTarget(int d, int f, int target) {
//         Integer[][] memo = new Integer[d + 1][target + 1];
//         return helper(d, f, target, memo);
//     }
    
//     public int helper(int d, int f, int target, Integer[][] memo) {
//         if (d == 0 || target <= 0) {
//             return d == target ? 1 : 0;
//         }
//         if (memo[d][target] != null) {
//             return memo[d][target];
//         }
//         memo[d][target] = 0;
//         for (int i = 1; i <= f; i++) {
//             memo[d][target] = (memo[d][target] + helper(d - 1, f, target - i, memo)) % 1000000007;
//         }
//         return memo[d][target];
//     }
//     */
};
