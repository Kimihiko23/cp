#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int a[N]={0};
int dp[N]={0};
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for(int i=1;i<n;i++)
    {
        cin >> a[i];
    }
    dp[1]=a[1];
    dp[2]=a[1];
    int mx=1e18;
    for(int i=3;i<=n;i++)
    {
        dp[i]=min(dp[i-1]+a[i-1],dp[i-2]+a[i-1]);
        
    }
    cout << dp[n];
    
   
}
