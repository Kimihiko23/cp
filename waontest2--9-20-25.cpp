#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+23;
int dp[N][4]={0};
int a[N]={0};
int n,k;
void read()
{
    cin >> n >>k;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }

}
void solve()
{
    // 1 ko nhan;
    // 2 nhan(*);
    // 3 ko nhan nhung sau khi 2;
    dp[1][2]=a[1]*k;
    dp[1][1]=a[1];
    dp[1][3]=-1e18;
    for(int i=2;i<=n;i++)
    {
        dp[i][2]=max({dp[i-1][2]+a[i]*k,dp[i-1][1]+a[i]*k,a[i]*k});
        dp[i][1]=max(a[i],dp[i-1][1]+a[i]);
        dp[i][3]=max(dp[i-1][2]+a[i],dp[i-1][3]+a[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max({ans,dp[i][1],dp[i][2],dp[i][3]});
    }
    cout << ans << "\n";

}
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
    read();
    solve();
    }
    
   
}
