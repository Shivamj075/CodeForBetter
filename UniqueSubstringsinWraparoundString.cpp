//LeetCode

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26,0);
        if(p.size()==0)
            return 0;
        int n=p.size(),len=0;
        dp[p[0]-'a']=1;
        int currLen=1;
        for(int i=1;i<n;i++){
            char prev = p[i-1];
            char curr = p[i];
            if((i>0 and p[i]-p[i-1]==1)  or (prev=='z' and curr=='a')){
                currLen++; 
            }
            else{
                currLen=1;
            }
            dp[curr-'a'] = max(dp[curr-'a'],currLen);
        }
        int ans=0;
        for(int i=0;i<26;i++)
            ans+=dp[i];
        return ans;
    }
};
