#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =1e5+23;
int n;
int a[N]={0},b[N]={0},c[N]={0};
int dp[N][3]={0};
void read()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
}
void solve()
{
    for(int i=0;i<=2;i++)
    {
        dp[1][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=max(dp[i-1][2],dp[i-1][1])+a[i];
        dp[i][1]=max(dp[i-1][2],dp[i-1][0])+b[i];
        dp[i][2]=max(dp[i-1][0],dp[i-1][1])+c[i];
    }
    int ans=0;
    for(int i=0;i<=2;i++)
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