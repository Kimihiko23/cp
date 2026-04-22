#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1000+5;
int n;
int a[N];
int dp[N]={0};
//bool dd[N][N];
map<pair<int,int>,bool> dd;
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
    int ans=0;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if (i!=j)
            {
                dd[{a[i],a[i]+a[j]}]=1;
                dd[{a[j],a[i]+a[j]}]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if (dd[{a[j],a[i]}])
            {
                dp[i]=max(dp[i],dp[j]+1);
                ans=max(ans,dp[i]);
            }
        }
    }
    cout << ans+1;

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
