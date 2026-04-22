#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+25;
int n;
int dp[N][N]={0};
int a[N]={0};
int pre[N]={0};
void read()
{
    cin >> n;
    cin >> a[1];
    //dp[1][1]=a[1];
    pre[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        cin >> a[i];
        dp[i-1][i]=a[i]+a[i-1];
        //dp[i][i]=a[i];
        pre[i]=pre[i-1]+a[i];
  
    }
}
void solve()
{
    for(int i=2;i<=n;i++)
    {
        for(int j=i-2;j>=1;j--)
        {
            dp[j][i]=1e18;
            for(int z=j;z<=i-1;z++)
            {
                dp[j][i]=min(dp[j][z]+dp[z+1][i]+pre[i]-pre[j-1],dp[j][i]);
            }
            //cout << dp[j][i] << " " << j << " " << i << "    ";
        }
        //cout << endl;
    }
    cout << dp[1][n];
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
