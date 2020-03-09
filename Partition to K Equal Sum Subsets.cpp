class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> visited(n+1,0);
        int sum=0;
        for(auto num:nums)
            sum+=num;
        return canPartition(nums,k,visited,0,0,0,sum/k);
    }
    
    bool canPartition(vector<int>&nums,int k,vector<int>&visited,int startIndex,int currSum,int currNum,int tarSum ){
        if(k==1)
            return true;
        if(currSum==tarSum and currNum>0)
            return canPartition(nums,k-1,visited,0,0,0,tarSum);
        
        for(int i=startIndex;i<nums.size();i++){
            if(!visited[i]){
                visited[i]=1;
                if(canPartition(nums,k,visited,i+1,currSum+nums[i],currNum++,tarSum))
                    return true;
                visited[i]=0;
            }
        }
        return false;
    }
};
