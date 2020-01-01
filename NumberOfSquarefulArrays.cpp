
bool isValid(int a, int b){
        long tmp = a + b;
        int num = sqrt(tmp);                          
        if(num*num == tmp){
            return true;
        }else{
            return false;
        } 
} 

void squareful(vector<int> &A,vector<int> &visited,int index,int &cnt){
    if(index==A.size()-1){
        if(isValid(A[index],A[index-1]))
            cnt++;
        return;
    }
    unordered_set<int> s;
    for(int i=index;i<A.size();i++){
        if(s.find(A[i])==s.end() and (index==0 or isValid(A[i],A[index-1]))){
            //visited[i] = 1;
            s.insert(A[i]);
            swap(A[i],A[index]);
            squareful(A,visited,index+1,cnt);
            swap(A[i],A[index]);
            //visited[i] = 0;
        }
    }
}
int Solution::solve(vector<int> &A) {
    int cnt=0;
    vector<int> visited(A.size(),0);
    squareful(A,visited,0,cnt);
    return cnt;
}

/*

int res=0;
void Helper(vector<int> A, int start, int end)
{
    if(start==end)
    {
         if(isValid(A[start-1],A[start]))
            res++;
        
        return;
    }
    
    for(int i=start; i<=end; i++)
    {
        cout<<"i: "<<i<<" "<<"start "<<start<<endl;
       if(start!=i && A[start] == A[i])
           continue;
        
       if(start ==0 || isValid(A[start-1],A[i]) && start>=1)
       {cout<<"in: "<<i<<" "<<"start "<<start<<endl;
           swap(A[start], A[i]);
       
        Helper(A,start + 1, end);
       }
    }
}

*/
