//LeetCode

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // if(matrix.empty())  return 0;
        // vector<vector<int>>dp(matrix.size()+1,vector<int>(matrix[0].size()+1,-1));
        // int res = 0;
        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;matrix[0].size();j++){
        //         res=max(res,solve(matrix,i,j,dp));
        //     }
        // }
        // return res*res;
        return memoization(matrix);
    }
    
//     int solve(vector<vector<char>> &matrix,int i,int j,vector<vector<int>> &dp){
//         if(i>=matrix.size() or j>=matrix[0].size())
//             return 0;
        
//         if(matrix[i][j]=='0'){
//             dp[i][j] = 0;
//             return 0;
//         }
//         if(dp[i][j]>=0)
//             return dp[i][j];
        
//         dp[i][j] =1+min(solve(matrix,i,j+1,dp),min(solve(matrix,i+1,j+1,dp),solve(matrix,i+1,j,dp)));
        
//         return dp[i][j];
//     }
        int memoization(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        vector<vector<int>> mem(matrix.size(), vector<int>(matrix[0].size(), -1));
        
        int res = 0;
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                res = max(res, solve(matrix, mem, i, j));
            }
        }
        return res * res;
    }
    
    int solve(vector<vector<char>>& matrix, vector<vector<int>>& mem, int i, int j) {
        if (i >= matrix.size() || j >= matrix[0].size()) return 0;
        if (mem[i][j] >= 0) return mem[i][j];
        if (matrix[i][j] == '0') return mem[i][j] = 0;
        mem[i][j] = min(min(solve(matrix, mem, i+1, j), solve(matrix, mem, i, j+1)),
                        solve(matrix, mem, i+1, j+1)) + 1;
        return mem[i][j];
    }
 
};
