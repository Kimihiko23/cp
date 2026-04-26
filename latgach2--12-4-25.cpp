#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e6+23;
const int mod=1e9+7;
int pre[N];
int n;
int dp[N];
void read()
{
    cin >> n;
}
void solve()
{
    pre[0]=1;
    pre[1]=3;
    //pre[2]=3;
    dp[1]=2;
    dp[0]=1;
    for(int i=2 ;i <= n; i++)
    {
        dp[i]+=dp[i-1]*2;
        dp[i]+=dp[i-2]*3;
        if(i>=3)
        {
            dp[i]+=pre[i-3]*2;

        }
        dp[i]%=mod;
        pre[i]=pre[i-1]+dp[i];
        
    }
    cout << dp[n];
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
