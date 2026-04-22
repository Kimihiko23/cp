#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2012;
bool dp[N][N]={false};
int n,q;
string a[N]={""};
string s;
void read()

{
    
    cin >> n >> q;
    cin >> s;
    for(int i=1;i<=s.size();i++)
    {
        a[i]=s[i-1];
    }
}
void solve()
{
    for(int i=1;i<=s.size();i++)
    {
        dp[i][i]=true;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if (a[i]==a[j])
            {
                dp[i][j]=max({dp[i][j],dp[i-1][j+1],dp[i+1][j-1]});
            }
            if (a[i]==a[j] && i-j==1)
            {
                dp[i][j]=true;
            }
            //cout << dp[i][j]<< " ";
        }
        //cout << "\n";
    }
    while (q--)
    {
        int l,r;
        cin >> l >> r;
        if (max(dp[l][r],dp[r][l]))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
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
