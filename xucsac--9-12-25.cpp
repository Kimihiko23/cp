#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =1e5+23;
int dp[100][10000]={0};
int a[N]={0};
int n,s=0;
void read()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        s+=a[i];
    }
}
void solve()
{
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        //dp[i][0]=-1;
        for(int j=s;j>=1;j--)
        {
            for(int z=1;z<=a[i];z++)
            {
                if (j-z>=0)
                dp[i][j]+=dp[i-1][j-z];
            }
        }
    }
    int mx=0;
    for(int i=1;i<=s;i++)
    {
        mx=max(mx,dp[n][i]);
    }
    int ans=0;
    for(int i=1;i<=s;i++)
    {
        if (dp[n][i]==mx)
        {
            ans=i;
            break;
        }
    } 
    cout << ans;  
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    read();
    solve();
   
    
}
