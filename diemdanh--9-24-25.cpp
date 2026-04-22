#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+23;
int dp[N][5]={0};
int mod=1e9+7;
int n;
void read()
{
    cin >> n;
}
void solve()
{
    dp[0][0]=1;
    dp[1][0]=2;
    dp[1][1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=1;j++)
        {
            dp[i][j]=(dp[i-2][j]+dp[i-1][j])%mod;
            if (j==1)
            {
                dp[i][j]+=(dp[i-2][0]+dp[i-1][0])%mod;
            }
        }
        
    }
    cout << (dp[n][1]+dp[n][0])%mod;
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
