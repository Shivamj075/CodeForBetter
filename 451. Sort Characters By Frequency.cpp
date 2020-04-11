class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++)
            mp[s[i]]++;
        string res="";
        vector<string>bucket(s.size()+1,"");
        //bucket sort
        for(auto ch:mp){
            int n=ch.second;
            char c = ch.first;
            bucket[n].append(n,c);
        }
        for(int i=s.size();i>=0;i--){
            if(!bucket[i].empty())
                res.append(bucket[i]);
        }
        return res;
    }
};
