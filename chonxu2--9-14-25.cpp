#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e6+23;
const int mod=1e9+7;
int dp[N]={0};
int n,W;
int w[123]={0};
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
    dp[0]=1;
    //for(int i=1;i<=W;i++)
    //dp[0][i]=1e18;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {

            //dp[j]=dp[j];
            if (j-w[i]>=0)
            {
                dp[j]+=dp[j-w[i]];
            }
            //cout << dp[i][j] << " " << i << " " << j << "\n";
            dp[j]%=mod;
        }
        //cout << "\n";
    }
    cout << dp[W];
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