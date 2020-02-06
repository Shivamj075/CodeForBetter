int LCS(string A,string B){
    int n = A.size(),m=B.size();
    vector<vector<int>> lcs(n+1,vector<int>(m+1,0));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(B[i-1]==A[j-1]){
                lcs[i][j] = 1+lcs[i-1][j-1];
            }
            else{
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }
    
    return lcs[n][m];
}

int Solution::solve(string A) {
    string str = A;
    reverse(str.begin(),str.end());
    
    return LCS(A,str);
}
