/*
InterviewBit

Subsets II
Given a collection of integers that might contain duplicates, S, return all possible subsets.
 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.
Example : If S = [1,2,2], the solution is:
[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]

*/

void solve(vector<int> &A,int i,vector<int> &subset,set<vector<int>> &ans){
    if(i==A.size()){
        ans.insert(subset);
        return;
    }
    
    solve(A,i+1,subset,ans);
    subset.push_back(A[i]);
    solve(A,i+1,subset,ans);
    subset.pop_back();
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    
    set<vector<int>> ans;
    vector<int> subset;
    sort(A.begin(),A.end());
    solve(A,0,subset,ans);

    vector<vector<int>> res;
    for(auto elem:ans){
        res.push_back(elem);
    }
    return res;
}
