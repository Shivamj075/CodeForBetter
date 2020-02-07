int Solution::maxProduct(const vector<int> &A) {
    int n=A.size();
    int max_ending = 1,min_ending=1;
    bool flag=0;
    int max_so_far = 1;
    for(int i=0;i<n;i++){
        if(A[i]>0){
            max_ending = max_ending*A[i];
            min_ending = min(min_ending*A[i],1);
            flag=1;
        }
        else if(A[i]==0){
            max_ending = 1;
            min_ending = 1;
        }
        else{
            int tmp = max_ending;
            max_ending = max(min_ending*A[i],1);
            min_ending = tmp*A[i];
        }
        if(max_so_far<max_ending)
            max_so_far = max_ending;
    }
    if(flag==0 and max_so_far==1)
        return 0;
    return max_so_far;
}
