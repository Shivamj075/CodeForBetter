/*

Largest Continuous Sequence Zero Sum
Find the largest continuous sequence in a array which sums to zero. Example:
Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}
 NOTE : If there are multiple correct answers, return the sequence which occurs first in the array. 


*/

vector<int> Solution::lszero(vector<int> &A) {
    vector<int> sum(A.size()+1);
    unordered_map<int,int> m;
    
    sum[0]=0;
    m[0]=0;
    int startIndex=-1,len=0;
    
    for(int i=1;i<=A.size();i++){
        sum[i]=sum[i-1]+A[i-1];
        if(!m.count(sum[i])){
            m[sum[i]]=i;
        }else if(i-m[sum[i]]>len){
            len=i-m[sum[i]];
            startIndex=m[sum[i]];
        }
    }

    vector<int> ans;
    for(int i=startIndex;len>0;len--,i++){
        ans.push_back(A[i]);
    }
    return ans;

}
