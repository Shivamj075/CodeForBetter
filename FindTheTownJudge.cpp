class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_map<int,int> in;
        unordered_map<int,int> out;
        if(trust.size()==0)
            return 1;
        for(int i=0;i<trust.size();i++){
            int elem1 = trust[i][0];
            int elem2 = trust[i][1];
            in[elem2]++;
            out[elem1]++;
        }
        
        for(auto ch:in){
            if(ch.second==N-1 and out.find(ch.first)==out.end()){
                return ch.first;
            }
        }
        
        return -1;
    }
};
