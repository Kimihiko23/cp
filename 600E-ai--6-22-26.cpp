#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 100005;

int n;
int color[N];
vector<int> adj[N];

int sz[N];
int heavy[N];

int cnt[N];
int sumFreq[N];

int mx;
int ans[N];

void dfs_sz(int u, int p) {
    sz[u] = 1;
    heavy[u] = -1;

    int best = 0;

    for (int v : adj[u]) {
        if (v == p) continue;

        dfs_sz(v, u);

        sz[u] += sz[v];

        if (sz[v] > best) {
            best = sz[v];
            heavy[u] = v;
        }
    }
}

void add_subtree(int u, int p, int val) {
    int c = color[u];

    if (val == 1) {
        sumFreq[cnt[c]] -= c;

        cnt[c]++;

        sumFreq[cnt[c]] += c;

        mx = max(mx, cnt[c]);
    }
    else {
        sumFreq[cnt[c]] -= c;

        cnt[c]--;

        sumFreq[cnt[c]] += c;
    }

    for (int v : adj[u]) {
        if (v == p) continue;
        add_subtree(v, u, val);
    }
}

void dfs(int u, int p, bool keep) {
    cout << u << " " << keep << "\n";
    for (int v : adj[u]) {
        if (v == p || v == heavy[u]) continue;
        dfs(v, u, false);
    }

    if (heavy[u] != -1)
        dfs(heavy[u], u, true);

    for (int v : adj[u]) {
        if (v == p || v == heavy[u]) continue;
        add_subtree(v, u, 1);
    }

    int c = color[u];

    sumFreq[cnt[c]] -= c;

    cnt[c]++;

    sumFreq[cnt[c]] += c;

    mx = max(mx, cnt[c]);

    ans[u] = sumFreq[mx];

    if (!keep) {
        add_subtree(u, p, -1);
        mx = 0;
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen("input.txt","r")) 
    {
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> color[i];

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_sz(1, 0);
    dfs(1, 0, true);

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}