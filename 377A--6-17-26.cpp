/*
tantei wa mou shindeiru
*/
#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define ll long long
#define se second
#define siesta main
using namespace std;
#define name "input"

const int MOD1 = 1000020409;
const int MOD = 1e9 + 7;
const int N = 505;

int n, m, k;
char a[N][N];
bool vis[N][N];

vector<pair<int,int>> ord;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y)
{
    vis[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if (vis[nx][ny]) continue;
        if (a[nx][ny] != '.') continue;

        dfs(nx, ny);
    }

    ord.pb({x, y});
}

void read()
{
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
}

void solve()
{
    int sx = -1, sy = -1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == '.')
            {
                sx = i;
                sy = j;
                break;
            }
        }
        if (sx != -1) break;
    }

    dfs(sx, sy);

    for (int i = 0; i < k; i++)
    {
        int x = ord[i].fi;
        int y = ord[i].se;
        a[x][y] = 'X';
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << a[i][j];
        cout << '\n';
    }
}

siesta()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (fopen("input.txt","r"))
    {
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }

    read();
    solve();
}