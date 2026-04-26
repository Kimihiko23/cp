#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2005;
const int INF = 1e18;

int n, m;
int a[N][N];
int dis[N][N][9];

// 8 directions: up, up-right, right, down-right, down, down-left, left, up-left
int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};

// opposite direction lookup (1↔5, 2↔6, 3↔7, 4↔8)
int opposite[9] = {0, 5, 6, 7, 8, 1, 2, 3, 4};

bool check(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

void bfs() {
    queue<tuple<int, int, int>> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int d = 0; d <= 8; d++)
                dis[i][j][d] = INF;

    dis[1][1][0] = 0;
    q.push({1, 1, 0}); // (x, y, dir=0 means no previous direction)

    while (!q.empty()) {
        auto [x, y, dir] = q.front();
        q.pop();

        for (int nd = 1; nd <= 8; nd++) {
            if (dir != 0 && nd == opposite[dir]) continue; // can't reverse directly

            int nx = x + dx[nd] * a[x][y];
            int ny = y + dy[nd] * a[x][y];

            if (!check(nx, ny)) continue;

            if (dis[nx][ny][nd] > dis[x][y][dir] + 1) {
                dis[nx][ny][nd] = dis[x][y][dir] + 1;
                q.push({nx, ny, nd});
            }
        }
    }
}

void read() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
}

void solve() {
    bfs();
    int ans = INF;
    for (int d = 0; d <= 8; d++)
        ans = min(ans, dis[n][m][d]);

    if (ans == INF)
        cout << -1;
    else
        cout << ans+1; // correct number of moves
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    read();
    solve();
}
