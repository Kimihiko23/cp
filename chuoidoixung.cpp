#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e3+5;
int dp[N][N]={0};
string s1, s2;
void read()
{
    cin >> s1;
    s2=s1;
    reverse(s2.begin(),s2.end());
}
void solve()
{
    int ans=0;
    for(int i=0; i<s1.size(); i++)
    {
        for(int j=0; j<s2.size(); j++)
        {
            int tam1=0,tam2=0,tam3=0;
            if (i>0 && j>0)
            {
                tam3=dp[i-1][j-1];
            }
            if (i>0) tam1=dp[i-1][j];
            if (j>0) tam2=dp[i][j-1];
            dp[i][j]=max(tam1, tam2);
            if (s1[i]==s2[j]) dp[i][j]=max(dp[i][j],tam3+1);
            
            ans=max(ans,dp[i][j]);
        
        }
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
