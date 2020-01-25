int Solution::compareVersion(string A, string B) {
    int i=0,j=0,n=A.size(),m=B.size();
    while(i<n or j<m){
        string x,y;
        while(i<n and A[i]=='0')
            i++;
        while(i<n and A[i]!='.'){
            x+=A[i];
            i++;
        }
        while(j<m and B[j]=='0')
            j++;
        while(j<m and B[j]!='.'){
            y+=B[j];
            j++;
        }
        if(x!=y){
            if(x.size()==y.size()){
                if(x.compare(y)>0)
                    return 1;
                return -1;
            }
            else{
                if(x.size()>y.size())
                    return 1;
                else
                    return -1;
            }
            
        }
        i++,j++;
    }
    while(i<n and A[i]=='0')
        i++;
    while(j<m and B[j]=='0')
        j++;
    if(i>=n and j>=m)
        return 0;
    if(i>j)
        return 1;
    return -1;
    
}
