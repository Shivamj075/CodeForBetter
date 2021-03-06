/*
https://www.interviewbit.com/problems/matrix-median/
Given a matrix of integers A of size N x M in which each row is sorted.

Find an return the overall median of the matrix A.

Note: No extra memory is allowed.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.



Input Format

The first and only argument given is the integer matrix A.
Output Format

Return the overall median of the matrix A.
Constraints

1 <= N, M <= 10^5
1 <= N*M  <= 10^6
1 <= A[i] <= 10^9
N*M is odd
For Example

Input 1:
    A = [   [1, 3, 5],
            [2, 6, 9],
            [3, 6, 9]   ]
Output 1:
    5
Explanation 1:
    A = [1, 2, 3, 3, 5, 6, 6, 9, 9]
    Median is 5. So, we return 5.

Input 2:
    A = [   [5, 17, 100]    ]
Output 2:
    17 ``` Matrix=
```
*/


int Solution::findMedian(vector<vector<int> > &A) {
    int rows=A.size(),cols=A[0].size();
    int min_elem=INT_MAX,max_elem=INT_MIN;
    int median = ((rows*cols)+1)/2;
    for(int i=0;i<rows;i++){
        min_elem = min(min_elem,A[i][0]);
        max_elem = max(max_elem,A[i][cols-1]);
    }
    int s=min_elem,e=max_elem;
    int cnt;
    while(s<=e){
        int mid=s+(e-s)/2;
        cnt=0;
        for(int i=0;i<rows;i++){
            cnt=cnt+(upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin());
        }
        if(cnt<median){
            s=mid+1;
        }
        else
            e=mid-1;
    }
    return s;
}
