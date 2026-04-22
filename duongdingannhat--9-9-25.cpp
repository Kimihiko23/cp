#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=100+23;

int a[N][N];
const int mod=1e9+7;
 int n;
void dyp()
{
    int dp[N][N]={0};
    for(int i=1;i<=n;i++)
    {
        dp[1][i]=a[1][i];
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int tam1,tam2;
            if (j+1<=n)
            {
                tam2=dp[i-1][j+1];
            }
            else
            {
                tam2=1e18;
            }
            if (j-1>=1)
            {
                tam1=dp[i-1][j-1];
            }
            else
            {
                tam1=1e18;
            }
            dp[i][j]=min(tam1,min(tam2,dp[i-1][j]))+a[i][j];
            dp[i][j]%=mod;
        }
    }
    int ans=1e18;
    for(int i=1;i<=n;i++)
    {
        ans=min(ans,dp[n][i]);
    }
    cout << ans;
    

}
main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
      freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char tam;

    cin >> n;

    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        cin >> a[i][j];
      }
    }




    /*int ans=1e18;
    for(int i=1;i<=n;i++)
    {
      ans=min(ans,dyp(i));
    }
    cout << ans;*/
    dyp();
    return 0;
}
