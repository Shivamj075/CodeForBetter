int Solution::bulbs(vector<int> &A) {
    int cnt=0;
    bool toggle =0;
    for(int i=0;i<A.size();i++){
        if(toggle)
            A[i] = 1-A[i];
        if(A[i]==0){
            A[i]=1;
            cnt++;
            if(!toggle)
                toggle = 1;
            else
                toggle = 0;
        }
    }
    return cnt;
}
