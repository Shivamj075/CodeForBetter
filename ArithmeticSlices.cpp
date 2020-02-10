//LeetCode
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<3)
            return 0;
        int i=0,j=1,k=2,len=2,ans=0;
        while(k<A.size()){
            if(A[k]-A[k-1]==A[j]-A[i]){
                len++;
                k++;
                continue;
            }
            ans+=((len-1)*(len-2))/2;
            i = k-1;
            j=k;
            len=2;
            k++;
        }
        ans+=((len-1)*(len-2))/2;
        
        return ans;
    }
    /*
   int numberOfArithmeticSlices(vector<int>& A) {
        
        if (A.size() < 3)
            return 0;
            
        int count = 0, contribution = 0, dist = A[1] - A[0];
        
        for (int i = 2; i < A.size(); ++i)
        {
            if (A[i] - A[i - 1] == dist)
            {
                ++contribution;
                count += contribution;
                continue;
            }
            
            contribution = 0;
            dist = A[i] - A[i - 1];
        }
        
        return count;
    }*/
};
