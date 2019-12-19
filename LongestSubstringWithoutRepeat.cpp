/*

Longest Substring Without Repeat

Given a string, find the length of the longest substring without repeating characters. 
Example: The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
For "bbbbb" the longest substring is "b", with the length of 1.

*/

int Solution::lengthOfLongestSubstring(string A) {
    unordered_map<int,int> um;
    int n = A.size();
    int len = 0,cnt=0;
    int l=0,r=0;
    while(r<n and l<n){
        if(um.find(A[r]-'0')==um.end()){
            cnt++;
            um[A[r]-'0']++;
            r++;
        }
        else if(um.find(A[r]-'0')!=um.end()){
            um.erase(A[l]-'0');
            l++;
            cnt--;
        }
        if(cnt>len)
            len = cnt;
    }
    return len;
    
}
