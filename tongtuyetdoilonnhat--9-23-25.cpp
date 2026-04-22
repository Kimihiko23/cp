#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+23;
int dp[N][2]={0};
int n,a[N]={0};

void read()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];

}
void solve()
{
    //1 chon b;
    //0 khong chon b chon 1;
    //dp[1][1]=a[1];
    //dp[1][0]=1;
    int ans=0;
    for (int i=2;i<=n;i++)
    {
        dp[i][1]=max
        (dp[i-1][1]+abs(a[i-1]-a[i]),
        dp[i-1][0]+abs(1-a[i]));
        dp[i][0]=max(
        dp[i-1][1]+abs(a[i-1]-1),
        dp[i-1][0]-abs(1-1));
        ans=max(ans,max(dp[i][0],dp[i][1]));
        
    }
    cout << ans;
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
