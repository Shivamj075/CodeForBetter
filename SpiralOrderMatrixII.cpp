vector<vector<int> > Solution::generateMatrix(int n) {
    
    vector<vector<int>> matrix;
    vector<int> a(n,0);
    for(int i=0;i<n;i++)
        matrix.push_back(a);
    int elem=1,row1=0,row2=n-1,col1=0,col2=n-1;
    
    while(elem!=n*n+1){
        for(int i=col1;i<=col2;i++){
            matrix[row1][i]=elem++;
        }
        row1++;
        for(int i=row1;i<=row2;i++){
            matrix[i][col2]=elem++;
        }
        col2--;
        for(int i=col2;i>=col1;i--)
            matrix[row2][i] = elem++;
        row2--;
        for(int i=row2;i>=row1;i--)
            matrix[i][col1] = elem++;
        col1++;
    }
    
    return matrix;
        
}
