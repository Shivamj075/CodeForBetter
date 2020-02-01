bool isPalind(string s){
    for(int i=0,j=s.size()-1;i<j;j--,i++){
        if(s[i]!=s[j])
            return false;
    }
    return true;
}

vector<vector<int> > Solution::solve(vector<string> &A) {
    unordered_map<string,int> um;
    vector<vector<int>> res;
    for(int i=0;i<A.size();i++){
        string s = A[i];
        reverse(s.begin(),s.end());
        um[s] = i;
    }
    
    if(um.count("")){
        for(int i=0;i<A.size();i++){
            if(A[i]!="" and isPalind(A[i])){
                res.push_back({um[""],i});
            }
        }
    }
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            string l = A[i].substr(0,j), r = A[i].substr(j);
            
            if(um.count(l) and isPalind(r) and um[l]!=i)
                res.push_back({i,um[l]});
            if(um.count(r) and isPalind(l)and um[r]!=i)
                res.push_back({um[r],i});
        }
    }
    return res;
}
