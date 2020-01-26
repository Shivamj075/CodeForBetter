
int Solution::solve(string A) {
    // O(N^2) O(1)
    int n=A.size(),plen=1;
    
    for(int i=1;i<n;i++){
        int start=0,end=i;
        bool palin=1;
        while(start<end){
            if(A[start]!=A[end]){
                palin = 0;
                break;
            }
            start++;
            end--;
        }
        if(palin){
            plen = i+1;
        }
    }
    return n-plen;
}
