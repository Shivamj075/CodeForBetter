//Atcoder Dp contest
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
const ll INF = 1e18L + 5;

ll fast_exp(int base, int exp) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%MOD;
       base=(base*base)%MOD;
       exp/=2;
    }
    return res%MOD;
}

unordered_map<int,vector<int>> graph;
int N;
// #define black 1
// #define white 2 //1-black and 2-white
// vector<bool> visited;
vector<vector<int>> dp;
int dfs(int src,int color,int par){
    if(dp[src][color]!=-1){
        return dp[src][color];
    }
    
    //dp[src][color] = 1;
    ll ans=1;
    for(auto neigh:graph[src]){
        if(neigh!=par){
            if(color==0){
                ans = ans*(dfs(neigh,0,src)+dfs(neigh,1,src))%MOD;
            }
            else{
                ans = ans*dfs(neigh,0,src)%MOD;
            }
        }
    }
    
    return dp[src][color]=ans;
}
int main(){
   
   int n;
   cin>>n;
   N=n;
   int u,v;
   graph.clear();
    //visited.resize(n+1);
    dp.clear();
    dp.resize(n+1,vector<int>(2,-1));
    
   for(int i=1;i<=n-1;i++){
       cin>>u>>v;
       graph[u].push_back(v);
       graph[v].push_back(u);
   }
   
   ll ans = (dfs(1,1,0)+dfs(1,0,0))%MOD;
   cout<<ans<<endl;
   return 0;
}
