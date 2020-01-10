vector<int> Solution::solve(vector<int> &A) 
{
    
    stack<int> input,temp;
    
    for(int i=A.size()-1; i>=0; i--)
    {
        
        input.push(A[i]);
        
    }
  
    while (!input.empty()) 
    { 
        int elem = input.top(); 
        input.pop(); 
  
        while (!temp.empty() && temp.top() > elem) 
        { 
            input.push(temp.top()); 
            temp.pop(); 
        } 
        temp.push(elem); 
    } 
    
    vector<int> ans;
  
    for(int i=0; i<A.size(); i++)
    {
        ans.push_back(temp.top());
        temp.pop();
        
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
    
}
