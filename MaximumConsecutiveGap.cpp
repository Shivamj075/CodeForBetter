/*

Maximum Consecutive Gap

Given an unsorted array, find the maximum difference between the successive elements in its sorted form. 
Try to solve it in linear time/space. Example :
Input : [1, 10, 5]
Output : 5 
Return 0 if the array contains less than 2 elements.
You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
You may also assume that the difference will not overflow.

*/

int Solution::maximumGap(const vector<int> &arr) {
    if(arr.size()<2)
        return 0;
    vector<int> A=arr;
    sort(A.begin(),A.end());
    int ans=0;
    for(int i=0;i<A.size()-1;i++){
        ans=max(ans,A[i+1]-A[i]);
    }
    return ans;
}
