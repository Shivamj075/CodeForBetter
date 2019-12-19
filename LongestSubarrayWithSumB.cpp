int Solution::solve(vector<int> &A, int k) {
    int n = A.size(),len=0,sum=0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        sum+=A[i];
        if(sum==k)
            len = i+1;
        if(mp.find(sum)==mp.end()){
            mp[sum]=i;
        }
        if(mp.find(sum-k)!=mp.end()){
            if(len<(i-mp[sum-k])){
                len = i-mp[sum-k];
            }
        }
    }
    if(len==0)
        return -1;
    return len;
}
