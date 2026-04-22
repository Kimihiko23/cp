#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+23;
int dp[100+23][N]={0};
int n,W;
int v[123]={0},w[123]={0};
void read()
{
    cin >> n>> W;
    for(int i=1;i<=n;i++)
    {
        cin >> w[i] >> v[i];
    }
}
void solve()
{
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=0;
        for(int j=W;j>=1;j--)
        {

            dp[i][j]=dp[i-1][j];
            if (j-w[i]>=0)
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    read();
    solve();
    
   
}
