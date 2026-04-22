#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=500+23;
int dp[N]={0};
int a[N]={0};
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++)
    {
        int mx=0;
        for(int j=i;j>=max((int)1,i-k+1);j--)
        {
            mx=max(mx,a[j]);
            dp[i]=max(dp[i],dp[j-1]+mx*(i-j+1));
        }
    }
    cout << dp[n];
    
   
}
