/* Recursive
void recur(vector<vector<int>> &A,int i,int j,int &ans,int n,int m){
    if(i>=n and j>=m){
        ans++;
        return;
    }
    if(i+1<n and A[i+1][j]!=1)
        recur(A,i+1,j,ans,n,m);
    if(j+1<m and A[i][j+1]!=1)
        recur(A,i,j+1,ans,n,m);
    
}
*/
int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int ans=0;
    int n = A.size(),m=A[0].size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int i=0;i<n;i++){
        if(A[i][0]==0)
            dp[i][0] = 1;
        else
            break;
    }

    for(int i=0;i<m;i++){
        if(A[0][i]==0)
            dp[0][i] = 1;
        else
            break;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(!A[i][j])
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }
    
    return dp[n-1][m-1];
}
