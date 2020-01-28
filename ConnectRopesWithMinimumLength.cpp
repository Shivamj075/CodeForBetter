int Solution::solve(vector<int> &A) {
    priority_queue<int,vector<int> , greater<int>> pq;
    
    for(int i=0;i<A.size();i++){
        pq.push(A[i]);
    }
    int cost = 0;
    while(!pq.empty() and pq.size()>1){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        cost+=(first+second);
        pq.push(first+second);
    }
    return cost;
}
