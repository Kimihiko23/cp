#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+23;
int dp[2][10][123]={0};
int a[N]={0};
int n,k;
void read()
{
    cin >> n>>k;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }

}
void solve()
{
    // 1 have
    //0 dont have
    dp[1][0][0]=-1e18;
    dp[0][0][0]=0;
    for(int i=0;i<=1;i++)
    {
        for(int j=1;j<=k;j++)
        {
            dp[i][0][j]=-1e18;
        }
    }
    /*for(int i=0;i<=k;i++)
    {
        dp[0][0][i]=-1e18;
    }
    dp[0][0][0]=0;
    dp[1][1][0]=-1e18;*/
    for(int i=1;i<=n;i++)
    {
        int cur=i%2;
        int pre=(i-1)%2;
        for(int j=0;j<=k;j++)
        {
            
            dp[0][cur][j]=dp[0][pre][j];
            if (j-1>=0)
            {
                dp[0][cur][j]=max(dp[0][cur][j],dp[1][pre][j-1]+a[i]);
            }
            dp[1][cur][j]=max(dp[1][pre][j],dp[0][pre][j]-a[i]);
            
            
        //cout << dp[1][i] << " " << dp[0][i] << "\n ";
        }
    }
    int ans=-1e18;
    for(int i=0;i<=k;i++)
    {
        ans=max({ans,dp[0][n%2][i],dp[1][n%2][i]});
    }
    cout << ans;

}
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    read();
    solve();
    
   
}
