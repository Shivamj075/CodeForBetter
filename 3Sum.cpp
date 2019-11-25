/*
https://www.interviewbit.com/problems/3-sum/

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers.

Assume that there will only be one solution

Example:
given array S = {-1 2 1 -4},
and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)

*/

int Solution::threeSumClosest(vector<int> &A, int B) {
    int n=A.size(),ans,diff=INT_MAX;
    sort(A.begin(),A.end());
    for(int i=0;i<n;i++){
        int l=i+1,r=n-1;
        while(l<r){
            int sum=A[i]+A[l]+A[r];
            if(abs(sum-B)<diff){
                diff=abs(sum-B);
                ans=sum;
            }
            if(diff==0)
                return ans;
            if(sum<B)
                l++;
            else
                r--;
        }
    }
    return ans;
}
