/*
Interviewbit

Permutations

Given a collection of numbers, return all possible permutations. Example: [1,2,3] will have the following permutations:
[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]
 NOTE
No two entries in the permutation sequence should be the same.
For the purpose of this problem, assume that all the numbers in the collection are unique.
Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS. Example : next_permutations in C++ / itertools.permutations in python.
If you do, we will disqualify your submission retroactively and give you penalty points.

*/


void dfs(vector<int>& nums, vector<int>& curr, vector<bool>& visit,vector<vector<int>> &res){
    if(curr.size()==nums.size()){
        res.push_back(curr);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(!visit[i]){
            curr.push_back(nums[i]);
            visit[i]=1;
            dfs(nums,curr,visit,res);
            curr.pop_back();
            visit[i]=0;
        }
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> ans;
    vector<bool> visit(A.size(),0);
    vector<int> curr;
    dfs(A,curr,visit,ans);
    
    return ans;
}
