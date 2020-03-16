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
bool ans=0;
void recur(vector<int>&A,int i,int sum){
    if(i>=A.size()){
        if(sum==0 or sum%360==0)
            ans=true;
        return;
    }
    
    recur(A,i+1,sum+A[i]);
    recur(A,i+1,sum-A[i]);
}
int main(){
    int n;
    cin>>n;
    vector<int>A(n);
    ans=0;
    for(int i=0;i<n;i++)
        cin>>A[i];
    recur(A,0,0);
    if(ans) cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
