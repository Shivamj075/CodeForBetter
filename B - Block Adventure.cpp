//Codeforces
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;
ll fast_exp(int base, int exp) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%MOD;
       base=(base*base)%MOD;
       exp/=2;
    }
    return res%MOD;
}

int main(){
    int t;
    cin>>t;
    while(t--){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> A(n);
    for(int i=0;i<n;i++)
        cin>>A[i];
    bool flag=0;
    for(int i=0;i<n-1;i++){
        m+=(A[i]-max(0,A[i+1]-k));
        if(m<0){
            flag=1;
            break;
        }
    }
    
    
    if(flag)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    }
    return 0;
}
