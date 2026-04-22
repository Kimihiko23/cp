#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N= 1e5 + 5;
int n;
int dp[N]={0};
int a[N]={0};
void read()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
}
void solve()
{
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1]+a[i];
        int sum=0;
        int mn=1e18;
        
        for(int j=i;j>=max((int)1,i-10+1);j--)
        {
            
            mn=min(mn,a[j]);
            
            sum+=a[j];
            
        }
        if (i-10>=0)
        dp[i]=min(dp[i],dp[max(0LL,i-10)]+sum-mn);
        //cout << dp[i] << "\n";
    }
    cout << dp[n];
    
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
