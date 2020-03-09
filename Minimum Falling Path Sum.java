class Solution {
    int[][] memo;
    public int minFallingPathSum(int[][] A) {
        int minPath = Integer.MAX_VALUE;
        memo = new int[A.length][A.length];
        for (int i = 0; i < A.length; i++){
            minPath = Math.min(minPath, findMinPath(A, 0, i));
        }
        return minPath;    
    }
    
    private int findMinPath(int[][] A, int row, int column){
        if (row == A.length - 1){
            return A[row][column];
        } 
        if (memo[row][column] != 0) {return memo[row][column];}
        int minPath = Integer.MAX_VALUE; 
        int value = A[row][column];
        if (column-1 >= 0)
            minPath = Math.min(minPath, findMinPath(A, row + 1, column - 1) + value);
        if (column+1 < A.length)
            minPath = Math.min(minPath, findMinPath(A, row + 1, column + 1) + value);
        minPath = Math.min(minPath, findMinPath(A, row + 1, column) + value);
        memo[row][column] = minPath;
        
        return minPath;
            
    }

}
