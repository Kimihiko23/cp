#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+23;
int a[N]={0};
int n=0;
int dp[N]={0};
void truycuu(int i)
{
    int tam=0;
    if (i>0)
    {
        //int tam1=1;
        for(int j=1;j<i;j++)
        {
            if (dp[j]+1==dp[i] && a[j]<a[i])
            {
                tam=j;
                break;
            }

        }
        truycuu(tam);
        if (tam!=0)
        cout << tam << " ";
    }
}
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
    for(int i=1;i<=n;i++)
    {
        dp[i]=1;
        for(int j=1;j<i;j++)
        {
            if (a[j]<a[i])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;i++)
    {
        res=max(res,dp[i]);
    }
    cout << res << "\n";
    for(int i=1;i<=n;i++)
    {
        if (dp[i]==res)
        {
            truycuu(i);
            cout << i;
            break;
        }
    }
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
