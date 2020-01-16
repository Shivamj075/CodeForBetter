#define ll long long
string Solution::solve(string A, int k)
{
    stack<pair<string,ll>>st;
    ll len = 0,n=A.size(),freq;
    string temp;
    for(int i=0;i<n;i++){
        if(isalpha(A[i])){
            len++;
            temp = A[i];
            st.push({temp,len});
        }
        else{
            freq=0;
            while(i<n and isdigit(A[i])){
                freq = freq*10 +(A[i]-'0');
                i++;
            }
            if(freq*len>=k)
                break;
            len = len*freq;
            i--;
        }
    }
    while(!st.empty()){
        pair<string,ll> p = st.top();
        st.pop();
        k = k%p.second;
        if(k==0)
            return p.first;
    }
    
}
