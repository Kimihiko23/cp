#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m;
int a[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct Point 
{
    int x, y;
};


vector<vector<int>> bfs(int sx, int sy) 
{
    vector<vector<int>> dist(n + 2, vector<int>(m + 2, -1));
    queue<Point> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;

    while (!q.empty()) 
    {
        auto [x, y] = q.front(); q.pop();
        for (int k = 0; k < 4; k++) 
        {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 1 && nx <= n && ny >= 1 &&
                 ny <= m && a[nx][ny] != 1 && dist[nx][ny] == -1) 
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return dist;
}

main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    freopen("RBGH.INP", "r", stdin);
    freopen("RBGH.OUT", "w", stdout);

    cin >> n >> m;
    swap(n,m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    int sx, sy, tx, ty;
    vector<pair<int, int>> goods;


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 2) sx = i, sy = j;
            if (a[i][j] == 3) tx = i, ty = j;
            if (a[i][j] == 4) goods.push_back({i, j});
        }
    }

    auto dist_from_start = bfs(sx, sy);

    auto dist_from_end = bfs(tx, ty);

    int ans = 1e9;
    for (auto [gx, gy] : goods) {
        if (dist_from_start[gx][gy] != -1 && dist_from_end[gx][gy] != -1)
            ans = min(ans, dist_from_start[gx][gy] + dist_from_end[gx][gy]);
    }

    cout << ans;

}
