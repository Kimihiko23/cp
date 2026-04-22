#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back

using namespace std;

const int N = 50005;
const int M_MAX = 50005;

// g[u][0]: đồ thị cho dịch vụ A, g[u][1]: đồ thị cho dịch vụ B
vector<pair<int, int>> g[N][2];
int n, m, k, l;
int ndfs[N], low[N], dem;
bool is_bridge[M_MAX * 3]; // Đánh dấu ID cạnh là cầu

void dfs(int u, int p_id, int ty) {
    ndfs[u] = low[u] = ++dem;
    for (auto &edge : g[u][ty]) {
        int v = edge.fi;
        int id = edge.se;
        if (id == p_id) continue;

        if (ndfs[v] == 0) {
            dfs(v, id, ty);
            low[u] = min(low[u], low[v]);
            // Điều kiện quan trọng: Nếu low[v] > ndfs[u] thì cạnh id là CẦU
            if (low[v] > ndfs[u]) {
                is_bridge[id] = true;
            }
        } else {
            low[u] = min(low[u], ndfs[v]);
        }
    }
}

void reset_dfs() {
    dem = 0;
    for (int i = 0; i <= n; i++) {
        ndfs[i] = low[i] = 0;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    if (!(cin >> n >> m >> k >> l)) return 0;

    int edge_id_counter = 0;

    // 1. Nối gốc 0 với các nút dịch vụ A vào đồ thị ty = 0
    for (int i = 0; i < k; i++) {
        int u; cin >> u;
        edge_id_counter++;
        g[0][0].pb({u, edge_id_counter});
        g[u][0].pb({0, edge_id_counter});
    }

    // 2. Nối gốc 0 với các nút dịch vụ B vào đồ thị ty = 1
    for (int i = 0; i < l; i++) {
        int u; cin >> u;
        edge_id_counter++;
        g[0][1].pb({u, edge_id_counter});
        g[u][1].pb({0, edge_id_counter});
    }

    // 3. Đọc M cạnh thực và thêm vào CẢ HAI đồ thị
    int start_real_id = edge_id_counter + 1;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        edge_id_counter++;
        // Cạnh thực dùng chung ID trong cả 2 đồ thị để dễ đánh dấu
        g[u][0].pb({v, edge_id_counter});
        g[v][0].pb({u, edge_id_counter});
        
        g[u][1].pb({v, edge_id_counter});
        g[v][1].pb({u, edge_id_counter});
    }

    // Chạy DFS cho dịch vụ A
    reset_dfs();
    dfs(0, -1, 0);

    // Chạy DFS cho dịch vụ B
    reset_dfs();
    dfs(0, -1, 1);

    // Đếm các cạnh thực (ID từ start_real_id trở đi) bị đánh dấu là cầu
    int ans = 0;
    for (int i = start_real_id; i <= edge_id_counter; i++) {
        if (is_bridge[i]) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}