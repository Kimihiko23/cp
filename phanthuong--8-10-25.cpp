#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
const int N=1e5+5;
int a[N];
int dp[N]={0};
int pos=-1;
void read()
{
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    cin >> k;
}
void truyvet(int i)
{
    if(i > 0)
    {
        if(dp[i] == dp[i - 1])
            truyvet(i - 1);
        else if(dp[i] == dp[i - 2] + a[i])
        {
            truyvet(i - 2);
            cout << i << " ";
        }
        else 
        {
            truyvet(i - 3);
            cout << i - 1 << " " << i << " ";
        }
    }
}
void solve()
{
    int ans=-1e18;
    if (k==1)
    {
        dp[1]=max(a[1],0LL);
        
        for(int i=2;i<=n;i++)
        {
            dp[i]=max({dp[i-2]+a[i],dp[i-1],a[i]});
            ans=max(ans,dp[i]);
            if (dp[i]==ans) pos=i;
        }
        cout << dp[n] << "\n";
        //truyvet1(pos);
        truyvet(n);
    }
    if (k==2)
    {
        dp[1]=max(a[1],0LL);
        dp[2]=max({a[1]+a[2],a[2],dp[1],a[1],0LL});
        for(int i=3;i<=n;i++)
        {
            dp[i]=max({dp[i-3]+a[i]+a[i-1],dp[i-2]+a[i],dp[i-1],a[i]});
            ans=max(ans,dp[i]);
            if (dp[i]==ans) pos=i;
        }
        cout << dp[n] << "\n";
        truyvet(n);
        //for(int i=1;i<=n;i++) cout << dp[i] << " ";
        //cout << "\n";
        //cout << pos << "\n";
        //truyvet2(pos);
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
