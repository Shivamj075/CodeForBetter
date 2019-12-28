
int visit[20][20];
void paths(vector<vector<int>>&A,int i,int j,int size,int &n,int &m,int tgt,int &total){
    if(A[i][j]==-1)
        return;
    if(size==tgt+2){
        if(A[i][j]==2){
            total++;
        }
        return;
    }
    if(i+1<n and visit[i+1][j]==0){
        visit[i+1][j] = 1;
        paths(A,i+1,j,size+1,n,m,tgt,total);
        visit[i+1][j] = 0;
    }
    if(i-1>=0 and visit[i-1][j]==0){
        visit[i-1][j] = 1;
        paths(A,i-1,j,size+1,n,m,tgt,total);
        visit[i-1][j] = 0;
    }
    if(j+1<m and visit[i][j+1]==0){
        visit[i][j+1] = 1;
        paths(A,i,j+1,size+1,n,m,tgt,total);
        visit[i][j+1] = 0;
    }
    if(j-1>=0 and visit[i][j-1]==0){
        visit[i][j-1] = 1;
        paths(A,i,j-1,size+1,n,m,tgt,total);
        visit[i][j-1] = 0;
    }
    return;
}

int Solution::solve(vector<vector<int> > &A) {
    int row,col;
    int n = A.size();
    int m = A[0].size();
    int tgt = 0,total=0;
 
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            
            visit[i][j] = 0;
            
            if(A[i][j]==1){
                row = i;
                col  = j;
            }
            
            if(A[i][j]==0)
                tgt++;
            
            if(A[i][j]==-1)
                visit[i][j] = 1;
        }
    }
   // cout<<tgt<<endl;
    visit[row][col] = 1;
    paths(A,row,col,1,n,m,tgt,total);
    
    return total;
    
}
