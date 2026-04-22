// copilot:disable
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int N=1e5+5;
int dp[N];
int t[N];
int r[N];
void read()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        cin>>r[i];
    }
    
}
void solve()
{
    /*for(int i=1;i<=n;i++)
    {
        cout << t[i] << " ";
    }
    cout << endl;
    for(int i=1;i<=n-1;i++)
    {
        cout << r[i] << " ";
    }*/
    dp[1]=t[1];
    dp[2]=min(dp[1]+t[2],r[1]);
    //cout << dp[1] << " " << dp[2] << " ";
    for(int i=3;i<=n;i++)
    {
        dp[i]=min(dp[i-1]+t[i],dp[i-2]+r[i-1]);
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
