/*

Subset
Given a set of distinct integers, S, return all possible subsets.
 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example : If S = [1,2,3], a solution is:
[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]

*/


void solve(vector<int> &A,int i,vector<int> &subset,vector<vector<int>> &ans){
    //vector<int> ans;
    if(i==A.size()){
        ans.push_back(subset);
        return;
    }
    solve(A,i+1,subset,ans);
    subset.push_back(A[i]);
    solve(A,i+1,subset,ans);
    subset.pop_back();
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int>> ans;
    vector<int> subset;
    sort(A.begin(),A.end());
    solve(A,0,subset,ans);
    sort(ans.begin(),ans.end());
    return ans;
}
