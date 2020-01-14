string Solution::solve(string A) {
    stack<char> s;
    vector<bool> visited(26,0);
    map<char,int> mp;
    for(int i=0;i<A.size();i++)
        mp[A[i]]++;
    for(int i=0;i<A.size();i++){
        mp[A[i]]--;
        if(visited[A[i]-'a'])
            continue;
        while(!s.empty() and s.top()>A[i] and mp[s.top()]>0){
            char ch = s.top();
            s.pop();
            visited[ch-'a'] =false;
        }
        s.push(A[i]);
        visited[A[i]-'a'] = true;
    }
    string ans="";
    while(!s.empty()){
        char ch = s.top();
        s.pop();
        ans+=ch;
    }
    
    reverse(ans.begin(),ans.end());
    
    return ans;
}
