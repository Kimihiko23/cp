#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =200+23;
int dp[N][N]={0};
int a[N],b[N];
int n,k;
void read()
{
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] >> b[i];
    }
}
void solve()
{
    for(int i=1;i<=n;i++)
    {
        //dp[i][0]=0;
        dp[i][1]=b[i];
    }
    for(int i=1;i<=n;i++)
    {
        //dp[i][1]=b[i];
        for(int j=1;j<=k;j++)
        {
            dp[i][j]=-1e18;
            dp[i][1]=b[i];
            for(int z=1;z<i;z++)
            {
                if (a[i]!=a[z])
                {
                    dp[i][j]=max(dp[i][j],dp[z][j-1]+b[i]);
                }
                //cout << dp[i][j] << " ";
            }
            //cout << dp[i][j] << " ";
        }
        //cout << "\n";
    }
    int ans=-1;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp[i][k]);

    }
    cout << ans << "\n";
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        read();
        solve();
    }
   
    
}
