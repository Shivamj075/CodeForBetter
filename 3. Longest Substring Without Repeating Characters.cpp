class Solution {
public:
    //O(n)
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
    //O(n^2)
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        if(s.empty())
            return 0;
        int cnt=0,res=1;
        int l=0,r=0;
        while(l<=r and r<s.size()){
            
            if(st.count(s[r])){
                res = max(res,r-l);
                while(st.count(s[r])){
                    st.erase(s[l++]);
                }
            }
            st.insert(s[r++]);
        }
        res = max(res,r-l);
        return res;
    }
};
