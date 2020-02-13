 bool solve(string s,string p){
        if(p.size()==0)
            return s.size()==0;
        
        bool firstMatch =(s!="" and (s[0]==p[0] or p[0]=='.'));
        
        if(p.size()>=2 and p[1]=='*'){
            return solve(s,p.substr(2)) or (firstMatch and solve(s.substr(1),p));
        }
        
        return firstMatch and solve(s.substr(1),p.substr(1));
    }
    
    int Solution::isMatch(const string A, const string B) {
    vector<vector<int>> dp(A.size()+1,vector<int>(B.size()+1,-1));
    return solve(A,B,0,0,dp);
}
/*
//Memoization
bool solve(string s,string p,int i,int j,vector<vector<int>>&dp){
    if(j>=p.size())
        return i>=s.size();
    
    if(dp[i][j]!=-1)
        return dp[i][j];
    bool firstMatch =  (s[i]==p[j] or p[j]=='.');
    if(j+1<p.size() and p[j+1]=='*'){
        return dp[i][j] = solve(s,p,i,j+2,dp) or (firstMatch and solve(s,p,i+1,j,dp));
    }
    
    return dp[i][j] = firstMatch and solve(s,p,i+1,j+1,dp);
}

*/
