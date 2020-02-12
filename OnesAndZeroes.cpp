//LeetCode

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> A;
        vector<vector<vector<int>>> dp(strs.size() + 1,
                                   vector<vector<int>>(m + 1,
                                                       vector<int>(n + 1, -1)));
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            int cnt0=0,cnt1=0;
            for(int j=0;j<s.size();j++){
                if(s[j]=='0')
                    cnt0++;
                else
                    cnt1++;
            }
            A.push_back({cnt0,cnt1});
        }
        
        return solve(A,dp,m,n,0);
    }
    /* O(k*m*n) space O(k*m*n)
    int solve(vector<pair<int,int>>&A,vector<vector<vector<int>>> &dp,int m,int n,int i){
        if(m<0 or n<0)
            return -1;
        if(i>=A.size())
            return 0;
        if(dp[i][m][n]!=-1)
            return dp[i][m][n];
        int cnt0 = A[i].first,cnt1=A[i].second;
        return dp[i][m][n] =  max(1+solve(A,dp,m-cnt0,n-cnt1,i+1),solve(A,dp,m,n,i+1));
    }
    */
    /* 
    //Time: O(kmn) space O(m*n)
    int findMaxForm(vector<string>& strs, int zeros, int ones) {
        vector<vector<int>> dp(zeros + 1, vector<int>(ones + 1));
        for (int i = 0; i < strs.size(); ++i)
        {
            int cur_z = 0, cur_o = 0;
            for (auto n : strs[i])
                n == '0' ? cur_z ++ : cur_o ++;
            for (int z = zeros; z >= cur_z; -- z)
                for(int o = ones; o >= cur_o; -- o)
            	    dp[z][o] = max(dp[z - cur_z][o - cur_o] + 1, dp[z][o]);
        }
        return dp[zeros][ones];
    }
    */
   
};
