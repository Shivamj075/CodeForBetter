#define mod 1000000007
int Solution::solve(vector<int> &A, vector<int> &B) {
    unordered_map<int,int> freqx,freqy;
    for(int i=0;i<A.size();i++){
        freqx[A[i]]++;
        freqy[B[i]]++;
    }
    int sum=0;
    for(int i=0;i<A.size();i++){
        int b = freqx[A[i]];
        int a = freqy[B[i]];
        sum+=((a-1)*(b-1));
        sum=sum%mod;
    }
    return sum;
}
