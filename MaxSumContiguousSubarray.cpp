int Solution::maxSubArray(const vector<int> &A) {
    
    int max_so_far = INT_MIN,max_till = 0;
    int n =A.size();
    for(int i=0;i<n;i++){
        max_till+=A[i];
        if(max_till>max_so_far)
            max_so_far = max_till;
        if(max_till<0)
            max_till = 0;
    }
    
    return max_so_far;
}
