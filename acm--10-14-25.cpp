#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<int> a[3];

void read()
{
    cin >> n;
    for (int i = 0; i < 3; i++)
    {
        a[i].resize(n);
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }
}

void solve()
{
    vector<int> s(n);
    for (int i = 0; i < n; i++) s[i] = a[0][i] + a[1][i] + a[2][i];
    int ans = LLONG_MAX;
    vector<vector<int>> pref(3, vector<int>(n + 1, 0));
    for (int i = 0; i < 3; i++)
        for (int j = 1; j <= n; j++)
            pref[i][j] = pref[i][j - 1] + a[i][j - 1];
    for (int i = 1; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            int s1 = pref[0][i] + pref[1][i] + pref[2][i];
            int s2 = (pref[0][j] - pref[0][i]) + (pref[1][j] - pref[1][i]) + (pref[2][j] - pref[2][i]);
            int s3 = (pref[0][n] - pref[0][j]) + (pref[1][n] - pref[1][j]) + (pref[2][n] - pref[2][j]);
            ans = min(ans, min({s1, s2, s3}));
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
