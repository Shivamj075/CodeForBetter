bool cmp(int a,int b){
    return a>b;
}
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    priority_queue<pair<int,pair<int,int>> > pq;
    int n = A.size();
    vector<int> ans;
    
    sort(A.begin(),A.end(),cmp);
    sort(B.begin(),B.end(),cmp);
    pq.push({A[0]+B[0],{0,0}});
    
    set<pair<int,int>> s;
    s.insert({0,0});
    while(!pq.empty()){
        pair<int,pair<int,int>> elem = pq.top();
        ans.push_back(elem.first);
        pq.pop();
        int i = elem.second.first;
        int j = elem.second.second;
        if(i+1<n and s.find({i+1,j})==s.end()){
            pq.push({A[i+1]+B[j],{i+1,j}});
            s.insert({i+1,j});
        }
        if(j+1<n and s.find({i,j+1})==s.end()){
            pq.push({A[i]+B[j+1],{i,j+1}});
            s.insert({i,j+1});
        }
        if(ans.size()==n)
            break;
    }
    
    return ans;
}
