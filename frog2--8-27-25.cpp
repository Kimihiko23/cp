#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =1e5+23;
int dp[N]={0};
int h[N]={0};

main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k;
    cin >> n >> k;
    int mx=1e18;
    for(int i=1;i<=n;i++)
    {
        dp[i]=mx;
    }
    for(int i=1;i<=n;i++)
    {
        cin >> h[i];
    }
    dp[1]=0;
    //if (n>1)
    
    dp[2]=abs(h[2]-h[1]);
    int st;
    for(int i=3;i<=n;i++)
    {
        if (i<k)
        {
            st=1;
        }
        else
        {
            st=i-k;
        }
        for(int j=st;j<i;j++)
        {
            dp[i]=min(dp[i],dp[j]+abs(h[i]-h[j]));
        }
    }
    
    cout <<dp[n];
    
}
