#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+23;
int dp[100+23][10000+23]={0};
int n,W;
int v[123]={0},w[123]={0};
void read()
{
    cin >> n>> W;
    //W=W*1024;
    for(int i=1;i<=n;i++)
    {
        cin >> w[i];
        
    }
}
void solve()
{
    ///dp[0][0]=1;
    for(int i=1;i<=W;i++)
    dp[0][i]=1e18;
    for(int i=1;i<=n;i++)
    {
        dp[0][i]=1e18;
        for(int j=0;j<=W;j++)
        {

            dp[i][j]=dp[i-1][j];
            if (j-w[i]>=0)
            {
                dp[i][j]=min(dp[i][j],dp[i][j-w[i]]+1);
            }
            //cout << dp[i][j] << " " << i << " " << j << "\n";
        }
        //cout << "\n";
    }
    cout << dp[n][W];
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
