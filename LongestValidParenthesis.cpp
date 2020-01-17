int Solution::longestValidParentheses(string A) {
    //stack<char> s;
   vector<int> dp(A.size(),0);
   dp.clear();
   int i=0,n=A.size();
   while(i<n){
       if(A[i]=='('){
           i++;
        continue;
       }
       else if(i>0 and A[i]==')'){
           if(A[i-1]=='('){
               if(i-2>=0)
                dp[i] = dp[i-2]+2;
                else
                    dp[i]+=(dp[i-1]+2);
           }
           else if(dp[i-1]!=0){
               int indx = i-dp[i-1]-1;
               if(indx>=0){
                   if(A[indx]=='('){
                   if(indx-1>=0)
                    dp[i]+=dp[i-1]+dp[indx-1]+2;
                   else
                    dp[i] = dp[i-1]+2;
               }
               }
               
           }
       }
        i++;
   }
   int ans=0;
   for(int i=0;i<n;i++){
       ans =max(ans,dp[i]);
   // cout<<dp[i]<<" ";
   }
   // cout<<endl;
    return  ans;
}
