#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =1e6+23;
//int n=1e3;
bool dp[3000][3000]={false};
int a[N]={0};
int n,m;
void read()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        dp[1][a[i]%m]=true;
    }

}
void solve()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int z=1;z<i;z++)
            {
                dp[i][j]=max(dp[i][j],dp[z][(j-a[i]%m+m)%m]);
            }
        }
    }
    bool ans=false;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp[i][0]);
    }
    if (ans)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    read();
    if (n<=m)
    solve();
    else
    {
        cout << "YES";
    }
   
    
}