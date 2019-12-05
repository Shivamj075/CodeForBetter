/*
InterviewBit
All Unique Permutations
Given a collection of numbers that might contain duplicates, return all possible unique permutations. Example : [1,1,2] have the 
following unique permutations:
[1,1,2]
[1,2,1]
[2,1,1]
 NOTE : No 2 entries in the permutation sequence should be the same. Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS.
 Example : next_permutations in C++ / itertools.permutations in python. If you do, we will disqualify your submission retroactively and
 give you penalty points.
 
 */
 
 void solve(vector<int>&A,vector<int> &perm,set<vector<int>> &ans,vector<bool> &visit){
    if(perm.size()==A.size()){
        ans.insert(perm);
        return;
    }
    for(int i=0;i<A.size();i++){
        if(!visit[i]){
            perm.push_back(A[i]);
            visit[i]=1;
            solve(A,perm,ans,visit);
            perm.pop_back();
            visit[i]=0;
        }
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    set<vector<int>> ans;
    vector<int> perm;
    vector<bool> visit(A.size(),0);
    solve(A,perm,ans,visit);
    
    vector<vector<int>> res;
    for(auto ch:ans)
        res.push_back(ch);
        
    return res;
    
}
