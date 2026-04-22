#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N= 1e5 + 23;
int dp[N];
int a[N];
int n;
void read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}
void solve()
{
    dp[1] = 0;
    dp[2] = abs(a[2] - a[1]);
    for(int i = 3; i <= n; i++)
        dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), 
        dp[i - 2] + abs(a[i] - a[i - 2]));
    cout << dp[n];
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
