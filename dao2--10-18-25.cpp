#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N = 55;

int n, m;
vector<string> g;
int distGrid[N][N];

void read()
{
    cin >> n >> m;
    g.assign(n, string());
    for (int i = 0; i < n; ++i) cin >> g[i];
}

void solve()
{

    vector<pair<int,int>> sources;
    vector<pair<int,int>> ships;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 'D') sources.push_back({i,j});
            if (g[i][j] == 'S') ships.push_back({i,j});
        }
    }

    if (sources.empty()) {

        if (!ships.empty()) {
            cout << "NO";
            return;
        } else {

            cout << 0;
            return;
        }
    }


    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            distGrid[i][j] = -1;

    queue<pair<int,int>> q;
    for (auto &p : sources) {
        distGrid[p.first][p.second] = 0;
        q.push(p);
    }

    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    while (!q.empty()) {
        auto u = q.front(); q.pop();
        int x = u.first, y = u.second;
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (distGrid[nx][ny] != -1) continue;

            distGrid[nx][ny] = distGrid[x][y] + 1;
            q.push({nx, ny});
        }
    }

    long long ans = 0;
    for (auto &s : ships) {
        int d = distGrid[s.first][s.second];
        if (d == -1) {
            cout << "NO";
            return;
        }
        ans += d;
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
