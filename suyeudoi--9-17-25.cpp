#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+23;
int dp[2][N]={0};
int a[N]={0};
int n;
void read()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }

}
void solve()
{
    // 1 +
    //0 -
    dp[1][1]=a[1];
    dp[0][1]=0;
    for(int i=2;i<=n;i++)
    {
        dp[1][i]=max(dp[1][i-1],dp[0][i-1]+a[i]);
        dp[0][i]=max(dp[0][i-1],dp[1][i-1]-a[i]);
        //cout << dp[1][i] << " " << dp[0][i] << "\n ";
    }
    cout << max(dp[1][n],dp[0][n]);

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
