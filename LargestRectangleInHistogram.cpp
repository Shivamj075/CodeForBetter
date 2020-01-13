int Solution::largestRectangleArea(vector<int> &A) {
    int i=0,answithtop,ans=0,n=A.size();
    stack<int> s;
    while(i<n){
        if(s.empty() or A[s.top()]<=A[i])
            s.push(i++);
        else{
            int tp = s.top();
            s.pop();
            if(s.empty())
                answithtop = A[tp]*i;
            else
                answithtop = A[tp]*(i-s.top()-1);
            ans = max(ans,answithtop);
        }
    }
    while(!s.empty()){
        int tp = s.top();
        s.pop();
        if(s.empty())
            answithtop = A[tp]*i;
        else
            answithtop = A[tp]*(i-s.top()-1);
            ans = max(ans,answithtop);
    }
    return ans;
}
