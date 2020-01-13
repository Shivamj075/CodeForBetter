int Solution::evalRPN(vector<string> &A) {
    stack<int> s;
    for(int i=0;i<A.size();i++){
        if(A[i]=="+" or A[i]=="-" or A[i]=="*" or A[i]=="/"){
            int top1= s.top();
            s.pop();
            int top2 = s.top();
            s.pop();
            //cout<<top1<<" "<<top2<<endl;
            int ans;
            if(A[i]=="+")
                ans =top1+top2;
            else if(A[i]=="-")
                ans = top2-top1;
            else if(A[i]=="*")
                ans = top1 * top2;
            else
                ans = top2/top1;
           // cout<<ans<<endl;
            s.push(ans);
                
        }
        else
            s.push(stoi(A[i]));
    }
    return s.top();
}
