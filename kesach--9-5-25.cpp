#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=500+23;
int dp[N];
int w[N]={0},h[N]={0};
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,l;
    cin >> n >> l;
    for(int i=1;i<=n;i++) cin >> h[i] >> w[i];
   
    for(int i=1;i<=n;i++)
    {
        dp[i]=1e18;
        int mx=0;
        int j=i;
        int tong=0;
        for(int j=i;j>=0 && tong<=l;j--)
        {
            tong+=w[j];
            if(tong>l) break;
            mx=max(mx,h[j]);
            dp[i]=min(dp[i],dp[j-1]+mx);
        }
        //cout << dp[i] << " ";
    }
    cout << dp[n];
    
   
}
