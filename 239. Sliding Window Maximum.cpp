class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
        vector<int> res;        
        int n = A.size();
        vector<int> left_max(n),right_max(n+1,INT_MIN);
        for(int i=0;i<n;i++){
            if(i%k==0)
                left_max[i] = A[i];
            else
                left_max[i] = max(left_max[i-1],A[i]);
            //cout<<left_max[i]<<" ";
        }
        //cout<<endl;
        for(int i=n-1;i>=0;i--){
            if((i+1)%k==0)
                right_max[i] = A[i];
            else
                right_max[i] = max(right_max[i+1],A[i]);
           // cout<<right_max[i]<<" ";
        }
        //cout<<endl;
        
        for(int i=0;i<n-k+1;i++)
            res.push_back(max(right_max[i],left_max[i+k-1]));
        return res;
    }
};
