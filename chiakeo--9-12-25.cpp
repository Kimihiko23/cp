#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =1e5+23;
int n;
int a[N];
bool dp[100][10000]={false};
int s=0;
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
    dp[0][0]=true;
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=true;
        for(int j=s;j>=0;j--)
        {
            bool tam=false;
            if (j-a[i]>=0)
            {
                tam=dp[i-1][j-a[i]];

            }
            dp[i][j]=max(tam,dp[i-1][j]);
        }

    }
    int ans=1e18;
    for(int i=0;i<=s;i++)
    {
        if (dp[n][i])
        {
            ans=min(ans,abs(i-(s-i)));
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
