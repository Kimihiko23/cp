#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
bool dp[N];
int n,m;
int a[N];
void read()
{
    cin >> n >> m;
    //cout << n << " " << m;
    dp[0]=true;
    for(int i=1;i <= m; i++)
    {
        cin >> a[i];
        dp[i]=false;
    }
}
void solve()
{
    sort(a+1,a+1+m);
    for(int i=1;i <= m; i++)
    {
        for(int j=n;j >= 0; j--)
        {
            int tam=j-a[i];
            if(tam>=0)
            {
                dp[j]=max(dp[j],dp[j-a[i]]);
            }
        }
    }
    for(int i=n;i >= 0; i--)
    {
        if(dp[i])
        {
            cout << i;
            break;
        }
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
    solve();

   
    
}
