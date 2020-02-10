//LeetCode

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        
        vector<int> dp(pairs.size()+1,1);
        
        for(int i=1;i<pairs.size();i++){
            int c = pairs[i][0],d=pairs[i][1];
            for(int j=0;j<i;j++){
                int a = pairs[j][0],b = pairs[j][1];
                if(b<c){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
        }
        int ans=1;
        for(int i=0;i<=pairs.size();i++){
            ans=max(ans,dp[i]);
        }
        return ans;
    }
    
//     void solve(vector<vector<int>>&A,int i,int &ans,int prev){
//         if(i>=A[0].size()){
//             ans++;
//             return;
//         }
        
//         vector<int> pair = A[0][i];
        
//         if(pair[0]<pair[1]){
            
//         }
//     }
};
