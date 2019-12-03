/*
InterviewBit

Combination Sum II
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers
sums to T. Each number in C may only be used once in the combination.
 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
Example : Given candidate set 10,1,2,7,6,1,5 and target 8, A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]


*/

void solve(vector<int> &A,int i,int B,vector<int> &subset,set<vector<int>> &ans,int sum){
    if(sum==B){
        ans.insert(subset);
        return;
    }
    if(i==A.size() or sum>B){
        return ;
    }
    
    solve(A,i+1,B,subset,ans,sum);
    
    subset.push_back(A[i]);
    solve(A,i+1,B,subset,ans,sum+A[i]);
    subset.pop_back();
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    set<vector<int>> ans;
    vector<int> subset;
    sort(A.begin(),A.end());
    solve(A,0,B,subset,ans,0);
    
    vector<vector<int>> res;
    for(auto elem:ans)
        res.push_back(elem);
    return res;
    
}
