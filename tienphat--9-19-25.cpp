#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=3123;
int n;
pair<int,int> a[N];
int dp[N]={0};
int pre[N]={0};
void read()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a+1,a+n+1);

}
void solve()
{
    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1]+a[i].first;
    }
    //dp[1]=a[1].second;
    for(int i=1;i<=n;i++)
    {
        dp[i]=1e18;
        for(int j=1;j<=i;j++)
        {
            dp[i]=min(dp[i],dp[j-1]+a[j].second +pre[i]-pre[j-1] -1LL*a[j].first*(i-j+1));
        }
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
