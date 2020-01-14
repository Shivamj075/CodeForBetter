int Solution::braces(string A) {
    stack<char> s,op;
    for(int i=0;i<A.size();i++){
        if(A[i]=='+' or A[i]=='-' or A[i]=='*' or A[i]=='/')
            op.push(A[i]);
        else if(A[i]!=')'){
            s.push(A[i]);
        }
        else{
            int cnt=0;
            while(s.top()!='(')
                s.pop(),cnt++;
            if(op.empty() or cnt==1)
                return 1;
            s.pop();
            s.push('1');
            op.pop();
        }
    }
    return 0;
}
