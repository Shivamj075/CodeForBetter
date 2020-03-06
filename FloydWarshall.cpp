vector<vector<int> > Solution::solve(vector<vector<int> > &A) {
    
    int n=A.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(A[i][j]==-1)
                A[i][j] = 100005;
        }
    }
    
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                A[i][j] = min(A[i][j],A[i][k]+A[k][j]);
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(A[i][j]==100005)
                A[i][j]=-1;
        }
    }
    
    return A;
}
