//LeetCode

class Solution {
public:
    int minSteps(int n) {
        
        if(n<=1)
            return 0;
        return 1+(int)solve(n,1,1,1);
    }
    
    long long solve(int n,int len,int item,bool copy){
        if(len>n)
            return INT_MAX;
        if(len==n)
            return 0;
        //int ans;
        if(copy){
            return 1+solve(n,len+item,item,false);
        }
        
        
        return 1+min(solve(n,len+item,item,false),solve(n,len,len,true));
    }
};
