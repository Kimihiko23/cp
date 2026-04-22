#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e3+23;
const int N2=2e3+30;
int dp[N][2023]={0};
int a[N]={0};
int n;
int dd[N2]={0};
void read()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }

}
void solve()
{
    // 1 +
    //0 -
    
    for(int i=1;i<=2000;i++)
    {
        //dp[0][i]=1;
        memset(dd, 0, sizeof(dd));
        for(int j=1;j<=n;j++)
        {
            
            
            dp[j][i]=dp[j-1][i];
            if (a[j]-i>=0)
            {
                dp[j][i]=max(dp[j][i],dd[a[j]-i]+1);
                dd[a[j]]=max(dd[a[j]-i]+1,dd[a[j]]);
            }
            if (dd[a[j]]==0)
            {
                dd[a[j]]=1;
            }
            //cout << dp[j][i] << " " << j << " "<<i <<"\n"; 
        }
        
        
        
    }
    int ans=0;
    for(int i=1;i<=2000;i++)
    {
        ans=max(ans,dp[n][i]);
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
