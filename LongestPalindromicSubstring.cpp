//LeetCode

class Solution {
public:
    string longestPalindrome(string s) {
        
        int start=0,end=0;
        for(int i=0;i<s.size();i++){
            
            
            int len = max(expandCentre(s,i,i+1),expandCentre(s,i,i));
            
            if(len > (end-start)) {
                start = i - ((len-1)/2);
                end = i + (len/2);
            }
            
        }
        return s.substr(start,end-start+1);
    }
    
    int expandCentre(string s,int left,int right){
        if(s.size()==0 or left>right)
            return 0;
        while(left>=0 and right<s.size() and s[left]==s[right]){
           // cnt++;
            left--;
            right++;
        }
        return right-left-1;
    }
};
