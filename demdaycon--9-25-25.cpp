#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
const int N=1e2+23;
int a[N];
int dp[N][1000]={0};
int n;
int pre[N]={0};
void read()
{
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
}
void solve()
{
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1000;j>=0;j--)
        {
            dp[i][j]=dp[i-1][j];
            if(j-a[i]>=0)
                dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%mod;
        }
    }
    for(int i=1;i<=1000;i++)
        pre[i]=(pre[i-1]+dp[n][i])%mod;
 
    int q;
    cin >> q;
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        cout << (pre[r]-pre[l-1]+mod)%mod << "\n";
       
    }
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
