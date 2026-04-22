#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+23;
int dp[1000+23][4096+23]={0};
int n,W;
int v[1023]={0},w[1023]={0};
void read()
{
    cin >> n>> W;
    W=W*1024;
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
        for(int j=1;j<=W;j++)
        {

            dp[i][j]=dp[i-1][j];
            if (j-w[i]>=0)
            {
                dp[i][j]=max(dp[i][j],dp[i][j-w[i]]+v[i]);
            }
            //cout << dp[i][j] << " " << i << " " << j << "\n";
        }
        //cout << "\n";
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
