#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =1e6+23;
const int mod=1e9+7;
int dp[N]={0};
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=N;i++)
    {
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    
}
