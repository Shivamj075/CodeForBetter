//LeetCode

class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+2,0);
        int ans = solve(n,dp);
        // for(int i=0;i<dp.size();i++)
        //     cout<<dp[i]<<" ";
        // cout<<endl;
        return ans;
       /*bootomup 
        vector<int> table(n + 1, 0);
	for (int i = 1; i <= n; ++ i) {
		table[i] = i;
		for (int j = 1; j * j <= i; ++ j) {
			table[i] = min(table[i], table[i - j * j] + 1);
		}
	}
	return table[n];
    */

    }
    
    int solve(int n,vector<int>&dp){
        
        if(n==0)
            return 0;
        
        if(dp[n]!=0)
            return dp[n];
        int res = INT_MAX;
        for(int i=1;i*i<=n;i++){
            if(i*i<=n){
                int curr = solve(n-(i*i),dp);
                if(curr!=INT_MAX and curr+1<res)
                    res = curr+1;
            }
        }
        
        dp[n] = res;
        
        return res;
    }
};
