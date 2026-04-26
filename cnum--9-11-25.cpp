#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =1e6+23;
int a[N]={0};
int dp[N][2]={0};
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
    for(int i=1;i<=n;i++)
    {
        int tam1=0,tam2=1;
        if (a[i]==2)
        {
            tam1=1;
            tam2=0;
        }
        dp[i][2]=min(dp[i-1][1],dp[i-1][2])+tam2;
        dp[i][1]=dp[i-1][1]+tam1;
        //cout << dp[i][1] << " " << dp[i][2] << "\n";
    }
    cout << min(dp[n][1],dp[n][2]);
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
