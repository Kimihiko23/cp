#include <bits/stdc++.h>
using namespace std;

const int maxN = 1005;
const int maxM = 100005;

int n, m, k;
vector<int> g[maxN];
bool visited[maxN];

void dfs(int u) {
    visited[u] = true;
    for (int v : g[u]) {
        if (!visited[v]) dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    freopen("GIAOSUA.INP", "r", stdin);
    freopen("GIAOSUA.OUT", "w", stdout);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        if (t >= k) {
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            ans++;
        }
    }
    cout << ans;
}
