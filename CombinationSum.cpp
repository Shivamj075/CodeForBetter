/*
InterviewBit
Combination Sum

Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
The same repeated number may be chosen from C unlimited number of times.
 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations themselves must be sorted in ascending order.
CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR ... (a1 = b1 AND a2 = b2 AND ... ai = bi AND ai+1 > bi+1)
The solution set must not contain duplicate combinations.
Example, Given candidate set 2,3,6,7 and target 7, A solution set is:
[2, 2, 3]
[7]


*/
void solve(vector<int> &A,int i,int B,vector<int> &subset,set<vector<int>> &ans){
    if(B==0){
        ans.insert(subset);
        return;
    }
    if(i==A.size() or B<0)
        return;
    
    
    solve(A,i+1,B,subset,ans);
    subset.push_back(A[i]);
    solve(A,i,B-A[i],subset,ans);
    subset.pop_back();
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    set<vector<int>> ans;
    vector<int> subset;
    solve(A,0,B,subset,ans);
    
    vector<vector<int>> res;
    for(auto ch:ans)
        res.push_back(ch);
    return res;
    
}
