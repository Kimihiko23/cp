#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1023;
char a[N][N];
bool dd[N][N];
int dem, n, m;

void loang(int x, int y)
{
    dd[x][y] = false;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int k = 0; k < 4; k++)
    {
        int u = x + dx[k];
        int v = y + dy[k];
        if (u >= 1 && u <= n && v >= 1 && v <= m && dd[u][v] && a[u][v] == '*')
        {
            dem++;
            loang(u, v);
        }
    }
}

void read()
{
    cin >> n >> m;
    swap(n,m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            dd[i][j] = true;
        }
}

void solve()
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (dd[i][j] && a[i][j] == '*')
            {
                dem = 1;
                loang(i, j);
                ans = max(ans, dem);
            }
    cout << ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    read();
    solve();
}
