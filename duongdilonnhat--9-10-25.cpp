#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =1000;
int dp[N][N]={0};
int a[N][N];
int n,m;
void read()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
        }
    }
}
void solve()
{
    for(int i=1;i<=n;i++)
    {
        dp[i][1]=a[i][1];
    }
    for(int j=2;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            int tam1=-1e18,tam2=-1e18;
            if (i-1>=1)

            {
                tam1=dp[i-1][j-1];
            }
            if(i+1<=n)
            {
            tam2=dp[i+1][j-1];
            }
            dp[i][j]=max(dp[i][j-1],max(tam1,tam2))+a[i][j];
        }
    }
    int ans=-1e18;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp[i][m]);
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