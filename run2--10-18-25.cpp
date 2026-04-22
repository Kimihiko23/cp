#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N = 1005;
int n, m;
char a[N][N];
int fire[N][N], distB[N][N];
int sx, sy, dx, dy;

void read()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            fire[i][j] = distB[i][j] = -1;
            if (a[i][j] == 'S') sx = i, sy = j;
            if (a[i][j] == 'D') dx = i, dy = j;
        }
}

void solve()
{
    queue<pair<int,int>> q;
    int dx4[4] = {-1,1,0,0};
    int dy4[4] = {0,0,-1,1};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == '*')
            {
                q.push({i,j});
                fire[i][j] = 0;
            }

    while (!q.empty())
    {
        auto [x,y] = q.front(); q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx4[k];
            int ny = y + dy4[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (a[nx][ny] == '#' || a[nx][ny] == 'D' || fire[nx][ny] != -1) continue;
            fire[nx][ny] = fire[x][y] + 1;
            q.push({nx,ny});
        }
    }

    queue<pair<int,int>> qb;
    qb.push({sx,sy});
    distB[sx][sy] = 0;
    while (!qb.empty())
    {
        auto [x,y] = qb.front(); qb.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx4[k];
            int ny = y + dy4[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (a[nx][ny] == '#' || distB[nx][ny] != -1) continue;
            int nd = distB[x][y] + 1;
            if (fire[nx][ny] != -1 && fire[nx][ny] <= nd) continue;
            distB[nx][ny] = nd;
            qb.push({nx,ny});
        }
    }

    if (distB[dx][dy] == -1) cout << "NO";
    else cout << distB[dx][dy];
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
