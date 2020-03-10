#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n,k;
    cin>>n>>k;
    vector<int> A(n+1);
    for(int i=1;i<=n;i++)
        cin>>A[i];
    vector<bool> dp(k+1);
    dp[0]=0;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(i<A[j])
                continue;
            dp[i]=dp[i]|!dp[i-A[j]];
        }
    }
    
    if(dp[k])
        cout<<"First"<<endl;
    else
        cout<<"Second"<<endl;
	return 0;
}
