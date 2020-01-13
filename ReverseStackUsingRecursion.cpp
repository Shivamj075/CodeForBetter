void reverse(int i,vector<int> A,vector<int> &v){
    if(i==A.size())
        return;
    int temp = A[i];
    reverse(++i,A,v);
    v.push_back(temp);
}
vector<int> Solution::solve(vector<int> &A) {
    
    vector<int> ans;
    reverse(0,A,ans);
    return ans;
    
    
}
