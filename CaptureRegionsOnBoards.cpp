/*
        T(n) = O(m*n)
        S(n) = O(1)
        */
void find(vector<vector<char>>& board, int i, int j, int m, int n){
        board[i][j] = '+';
        if(i+1 < m && board[i+1][j]=='O'){
            find(board,i+1,j,m,n);
        }
        if(i-1 >= 0 && board[i-1][j]=='O'){
            find(board,i-1,j,m,n);
        }
        if(j+1 < n && board[i][j+1]=='O'){
            find(board,i,j+1,m,n);
        }
        if(j-1 >= 0 && board[i][j-1]=='O'){
            find(board,i,j-1,m,n);
        } 
    }

void Solution::solve(vector<vector<char> > &board) {
     
        if(board.empty()){
            return;
        }
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i++){
            if(board[i][0]=='O')
                find(board, i, 0, m, n);
            
            if(board[i][n-1]=='O')
                find(board, i, n-1, m, n);
        }
        
        for(int i = 0; i < n; i++){
            if(board[0][i]=='O')
                find(board, 0, i, m, n);
            
            if(board[m-1][i]=='O')
                find(board, m-1, i, m, n);
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j]=='+'){
                    board[i][j]='O';
                }
            }
        }   
    
}
