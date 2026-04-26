#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e6+23;
int pre[N];
int dp[N][2];
int a[N];
int n,k;
void read()
{
    cin >> n >> k;
    pre[0]=0;
    a[0]=0;
    dp[0][1]=0;
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        pre[i]=pre[i-1]+a[i];
        dp[i][0]=0;
        dp[i][1]=a[i];
    }
    if (k==n)
    {
        cout << pre[N];
        exit(0);
    }
}
void solve()
{
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        for(int j=i;j>=max(i-k,(int)0);j--)
        {
            dp[i][1]=max(dp[i][1],pre[i]-pre[j]+dp[j][0]);
        }
    }
    int ans=max(dp[n][0],dp[n][1]);
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
