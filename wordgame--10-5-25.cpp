#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000+23;
string s;
int dp[N][N]={0};
void read()
{
    cin >> s;
    s=" "+s;
}   
void solve()
{
    int n=s.size()-1;
    for(int i = 1 ; i <= n ; i++)
	    dp[i][i] = 0;

    for(int i = 1 ; i <= n - 1 ; i++)
    {
    	if(s[i] == s[i + 1])
    		dp[i][i + 1] = 0;
    	else
    	    dp[i][i + 1] = 1;
    }
 

    for(int i=1;i<=n;i++)
    {
        for(int j=i-2;j>=1;j--)
        {
            if (s[i]!=s[j])
            {
                dp[j][i]=min(dp[j+1][i],dp[j][i-1])+1;
            }
            else
            {
                dp[j][i]=dp[j+1][i-1];
            }
        }
    }
    cout << max(dp[1][n],dp[n][1]);
    
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