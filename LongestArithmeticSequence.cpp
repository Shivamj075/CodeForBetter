//LeetCode

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        vector <unordered_map <int,int>> dp (A.size ());
        int ret = 0;
        
        for (int i = 1; i < A.size (); i++)
        {
            for (int j = 0; j < i; j++)
            {
                int diff = A[i] - A[j];
                if (!dp [j].count (diff))
                    dp [i][diff] = 2;
                else
                    dp [i][diff] = dp [j][diff] + 1;
                
                ret = max (ret, dp[i][diff]);
            }
        }
        
        return ret;
    }
};
