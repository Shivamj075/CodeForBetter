#define MOD 10000003
int Solution::seats(string A) {
    vector<int> pos;
    for(int i=0;i<A.size();i++){
        if(A[i]=='x')
            pos.push_back(i);
    }
    
    int median = pos.size()/2;
    int ans=0,occup=1;
    for(int i=0;i<median;i++){
        ans+=(pos[median]-pos[i]-occup);
        ans=ans%MOD;
        occup++;
    }
    occup=1;
    for(int i=median+1;i<pos.size();i++){
        ans+=(pos[i]-(pos[median]+occup));
        ans=ans%MOD;
        occup++;
    }
    
    return ans;
}
