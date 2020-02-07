int Solution::numDecodings(string A) {
    if(A[0]=='0')
        return 0;
    int n = A.size();
    int ways[n+1];
    
    if(A.size()==1)
        return 1;
    
    ways[0] = 1;
    ways[1] = 1;
    for(int i=2;i<=n;i++){
        ways[i] = 0;
        if(A[i-1]>'0')
            ways[i] = ways[i-1];
        if(A[i-1]=='0' and A[i-2]>'2')
            return 0;
        if((A[i-2]<'2' and A[i-2]>'0') or (A[i-2]=='2' and A[i-1]<='6'))
            ways[i]+=ways[i-2];
    }
    
    return ways[n];
}
                        
