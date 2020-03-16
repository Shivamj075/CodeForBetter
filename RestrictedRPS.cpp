//Codeforces DP approach

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

int dp[105][105][105],par[105][105][105];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a,b,c;
        string seq;
        cin>>n>>a>>b>>c>>seq;
 
        memset(dp,-1,sizeof(dp));
        memset(par,-1,sizeof(par));
 
        // r,p,s 
        // -> r+1,p,s
        // -> r,p+1,s
        // -> r,p,s+1
        dp[0][0][0] = 0;
        for(int r=0;r<=a;r++)
        {
            for(int p=0;p<=b;p++)
            {
                for(int s=0;s<=c;s++)
                {
                    if( dp[r+1][p][s] < dp[r][p][s] )
                    {
                        dp[r+1][p][s] = dp[r][p][s];
                        par[r+1][p][s] = 1;
                    }
                    if( dp[r][p+1][s] < dp[r][p][s] )
                    {
                        dp[r][p+1][s] = dp[r][p][s];
                        par[r][p+1][s] = 2;
                    }
                    if( dp[r][p][s+1] < dp[r][p][s] )
                    {
                        dp[r][p][s+1] = dp[r][p][s];
                        par[r][p][s+1] = 3;
                    }
                    if( seq[r+p+s] == 'S' )
                    {
                        if( dp[r+1][p][s] < dp[r][p][s] + 1 )
                        {
                            dp[r+1][p][s] = dp[r][p][s] + 1;
                            par[r+1][p][s] = 1;
                        }
                    }
                    if( seq[r+p+s] == 'R' )
                    {
                        if( dp[r][p+1][s] < dp[r][p][s] + 1 )
                        {
                            dp[r][p+1][s] = dp[r][p][s] + 1;
                            par[r][p+1][s] = 2;
                        }
                    }
                    if( seq[r+p+s] == 'P' )
                    {
                        if( dp[r][p][s+1] < dp[r][p][s] + 1 )
                        {
                            dp[r][p][s+1] = dp[r][p][s] + 1;
                            par[r][p][s+1] = 3;
                        }
                    }
                }
            }
        }
        if( 2*dp[a][b][c] < n )
        {
            cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n";
            int x = a, y = b, z = c;
            string ans = "";
            for(int i=0;i<n;i++)
            {
                int p = par[x][y][z];
                if( p == 1 )
                {
                    ans += 'R';
                    x--;
                }
                else if( p == 2 )
                {
                    ans += 'P';
                    y--;
                }
                else if( p == 3 )
                {
                    ans += 'S';
                    z--;
                }
            }
            reverse(ans.begin(),ans.end());
            cout<<ans<<endl;
        }
    }
    return 0;
}
