//Leetcode

class Solution {
public:
    int splitArray(vector<int>& A, int m) {
        int n =A.size();
        long long total=0,maxi=0;
        for(auto x:A){
            total+=x;
            maxi= max(maxi,1LL*x);
        }
        long long l=maxi,r=total;
        while(l<=r){
            long long mid = (l+r)/2;
            if(isValid(A,mid,m))
                r = mid-1;
            else
                l = mid+1;
        }
        return l;
    }
    
    bool isValid(vector<int>&A,long long mid,int m){
        long long sum=0,cnt=1;
        for(int i=0;i<A.size();i++){
            sum+=A[i];
            if(sum>mid){
                sum = A[i];
                cnt++;
            }
            if(cnt>m)
                return 0;
        }
        
        return 1;
    }
};
