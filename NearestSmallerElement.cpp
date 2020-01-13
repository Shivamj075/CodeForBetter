vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> s;
    int n = A.size();
    vector<int> ans(n,-1);
    for(int i=n-1;i>=0;i--){
        if(s.empty() or A[s.top()]<=A[i])
            s.push(i);
        else{
            while(!s.empty() and A[s.top()]>A[i]){
                ans[s.top()] = A[i];
                s.pop();
            }
            s.push(i);
        }
    }
    return ans;
}
