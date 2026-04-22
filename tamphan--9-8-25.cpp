#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+23;
int dp[N]={0};
const int mod=1e9+7;
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    dp[0]=1;
    dp[1]=3;
    int n;
    cin >> n;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]*2+dp[i-2]*2;
        dp[i]%=mod;
    }
    cout << dp[n];

    
   
}
