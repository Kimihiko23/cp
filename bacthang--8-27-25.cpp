#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+23;
const int mod=14062008;
int dp[N]={0};
//int dd[N]={0};
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k;
    int tam;
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        dp[i]=1;
    }
    for(int i=1;i<=k;i++)
    {
        cin >> tam;
        dp[tam]=0;
    }
    dp[1]=1;
    dp[2]=dp[2]*dp[1];
    for(int i=3;i<=n;i++)
    {
        //if (dp[i]==0) continue;
        dp[i]=((dp[i-1]*dp[i])%mod+(dp[i-2]*dp[i])%mod)%mod;
    }
    cout << dp[n];
}
