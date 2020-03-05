vector<string> arr;
void dfs(int i,int j,int n,int m){
    if(i<0 or j<0 or j>=m or i>=n)
        return;
    if(arr[i][j]!='X')
        return;
    arr[i][j] = 'O';
    dfs(i-1,j,n,m);
    dfs(i,j-1,n,m);
    dfs(i+1,j,n,m);
    dfs(i,j+1,n,m);
}
int Solution::black(vector<string> &A) {
    arr = A;
    int n=A.size();
    int m = A[0].size();
    //vector<vector<bool>> visit(n,vector<bool>(m,0));
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='X'){
                dfs(i,j,n,m);
                ans++;
            }
        }
    }
    
    return ans;
}
