//LeetCode

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        // vector<int>ans;
        // vector<int>elem;
        vector<int> res;
        if(nums.size()==0)
            return res;
        if(nums.size()==1)
            return nums;
        // solve(nums,0,elem,ans);
        int n=nums.size(),len=1;
        vector<int> dp(n+1,1);
        sort(nums.begin() , nums.end()); 
        dp[0]=1,dp[1]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if((nums[i]%nums[j]==0) and (dp[j]+1>dp[i])){
                    dp[i]=1+dp[j];
                }
            }
            len = max(len,dp[i]);
        }
        int want = len;
        cout<<want<<endl;
        if(want==1){
            res.push_back(nums[0]);
            return res;
        }
            
        for(int i=n-1;i>=0;i--){
            if(dp[i]==want){
                want--;
                res.push_back(nums[i]);
            }
        }
        return res;
    }
    /*
    //Recursive 
    void solve(vector<int>&A,int i,vector<int>&elem,vector<int>&ans){
        if(i>=A.size()){
            bool flag=0;
            int n=elem.size(),m=ans.size();
            for(int j=0;j<n-1;j++){
                if(elem[j]%elem[j+1]==0 or elem[j+1]%elem[j]==0)
                    continue;
                else
                    flag=1;
            }
            if(flag==0 and n>m){
                ans.clear();
                for(int i=0;i<n;i++)
                    ans.push_back(elem[i]);
            }
            
            return;
        }
        solve(A,i+1,elem,ans);
        int n=elem.size();
        if(n>=1){
            if(elem[n-1]%A[i]==0 or A[i]%elem[n-1]==0){
                 elem.push_back(A[i]);
                 solve(A,i+1,elem,ans);
            }
        }
        elem.push_back(A[i]);
        solve(A,i+1,elem,ans);
        elem.pop_back();
    }*/
};
