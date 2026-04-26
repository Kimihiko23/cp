#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =1e5+23;
int dp[123][12234]={0};
int w[123]={0},v[123]={0},a[123]={0};
int n,W;
void read()
{
    cin >> n >> W;
    for(int i=1;i<=n;i++)
    {
        cin >> w[i] >> v[i] >> a[i];
    }

}
void solve()
{
    for(int i=0;i<=W;i++)
    {
        dp[0][i]=-1e18;
    }
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            
            //dp[i][j]=dp[i-1][j];
            for(int y=0;y<=a[i];y++)
            {
            if (j-w[i]*y>=0 && a[i])
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]*y]+v[i]*y);

            }
        }
        }
    }
    int ans=0;
    for(int i=1;i<=W;i++)
    {
        ans=max(ans,dp[n][i]);
    }
    cout << ans;
    
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    read();
    solve();
   
    
}
