/*
https://www.interviewbit.com/problems/grid-unique-paths/
A robot is located at the top-left corner of an A x B grid (marked ‘Start’ in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).

How many possible unique paths are there?

Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.

Example :

Input : A = 2, B = 2
Output : 2

2 possible routes : (0, 0) -> (0, 1) -> (1, 1) 
              OR  : (0, 0) -> (1, 0) -> (1, 1)
*/
int solve(int i,int j){
    if(i==1 and j==1)
        return 1;
    if(i==1)
        return solve(i,j-1);
    if(j==1)
        return solve(i-1,j);
    return solve(i-1,j)+solve(i,j-1);
}
int Solution::uniquePaths(int A, int B) {
    
    int ans=solve(A,B);
    
    return ans;
}
