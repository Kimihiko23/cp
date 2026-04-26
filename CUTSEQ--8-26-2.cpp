#include <bits/stdc++.h>
#define int long long
using namespace std;

main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("CUTSEQ.INP","r",stdin);
    freopen("CUTSEQ.OUT","w",stdout);
    int n,c;
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) 
    {
        cin >> a[i];
    }
    vector<int> dp(n + 1, 0);
    dp[0] = -c;
    for (int i = 1; i <= n; ++i) 
    {
        dp[i] = LLONG_MAX;
        int min_val = a[i - 1];
        int max_val = a[i - 1];
        for (int j = i - 1; j >= 0; --j) 
        {
            min_val = min(min_val, a[j]);
            max_val = max(max_val, a[j]);
            int coverage = max_val - min_val + 1;
            int current_cost = dp[j] + c + coverage;
            dp[i] = min(dp[i], current_cost);
        }
    }
    cout << dp[n] << endl;
}