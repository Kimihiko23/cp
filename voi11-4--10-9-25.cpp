#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int N= 2e5 + 25;
//int a[N]={0};
//int b[N]={0};
pair<int,int> a[N];
int dp[N]={0};
int pre[N]={0};
void read()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i].first;
        a[i].second=1;
    }
    for(int i=n+1;i<=n*2;i++)
    {
        cin >> a[i].first;
        a[i].second=0;
    }
    sort(a+1,a+n*2+1);
    n*=2;
    /*for(int i=1;i<=n;i++)
    {
        cout << a[i].first << " " << a[i].second << "\n";
    }*/
    
}
void solve()
{
    int ans=0;
    //cout << n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(a[j].second!=a[i].second)
            {
                //cout << "gay";
                dp[i]=max(dp[i],pre[j]+1);
            }
            ans=max(ans,dp[i]);
        }
        pre[i]=max({pre[i-1],dp[i-1],pre[i]});
        //cout << dp[i] << " " << pre[i] << "\n";
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
