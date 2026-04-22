#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =5e3+23;
int n,p;
int dp[N][N]={0},pre[N][N]={0};
int a[N],b[N];
void read()
{
    cin >> n >> p;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
}
void solve()
{
    int ans=-1e18;
    pre[0][0]=-1e18;
    pre[0][1]=-1e18;
    pre[1][0]=-1e18;
    for(int i=1;i<=n;i++)
    {
        
        for(int j=1;j<=n;j++)
        {
            pre[i][j]=-1e18;
            dp[i][j]=-1e18;
            if (abs(i-j)<=p)
            {
            
                dp[i][j]=max(0+a[i]+b[j],pre[i-1][j-1]+a[i]+b[j]);
            }
            pre[i][j]=max({pre[i-1][j],pre[i][j-1],dp[i][j]});
            
            ans=max(ans,dp[i][j]);
        }
        
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
