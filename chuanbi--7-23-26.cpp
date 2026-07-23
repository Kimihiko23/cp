#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;

const int N = 2e5 + 23;
const int LOG = 20;

struct Edge
{
    int u, v, w;
    bool operator < (const Edge &other) const
    {
        return w < other.w;
    }
};

int n, m, q;
int par[N], sz[N];
vector<pair<int,int>> g[N];

int dep[N];
int up[N][LOG];
int dist[N];

int findpar(int v)
{
    if(par[v] == v)
        return v;
    return par[v] = findpar(par[v]);
}

void joinset(int a, int b)
{
    a = findpar(a);
    b = findpar(b);

    if(a == b)
        return;

    if(sz[a] < sz[b])
        swap(a, b);

    sz[a] += sz[b];
    par[b] = a;
}

void dfs(int u, int p)
{
    up[u][0] = p;

    for(int i = 1; i < LOG; i++)
        up[u][i] = up[up[u][i-1]][i-1];

    for(auto x : g[u])
    {
        int v = x.fi;
        int w = x.se;

        if(v == p)
            continue;

        dep[v] = dep[u] + 1;
        dist[v] = dist[u] + w;

        dfs(v, u);
    }
}

int lca(int u, int v)
{
    if(dep[u] < dep[v])
        swap(u, v);

    int k = dep[u] - dep[v];

    for(int i = 0; i < LOG; i++)
        if(k & (1LL << i))
            u = up[u][i];

    if(u == v)
        return u;

    for(int i = LOG - 1; i >= 0; i--)
    {
        if(up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];
}

void read()
{
    cin >> n >> m >> q;
}

void solve()
{
    vector<Edge> edge(m);

    for(int i = 0; i < m; i++)
        cin >> edge[i].u >> edge[i].v >> edge[i].w;

    sort(edge.begin(), edge.end());

    for(int i = 1; i <= n; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }

    for(auto e : edge)
    {
        if(findpar(e.u) != findpar(e.v))
        {
            joinset(e.u, e.v);
            g[e.u].pb({e.v, e.w});
            g[e.v].pb({e.u, e.w});
        }
    }

    dfs(1, 0);

    while(q--)
    {
        int u, v;
        cin >> u >> v;

        int p = lca(u, v);

        cout << dist[u] + dist[v] - 2 * dist[p] << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++)
    {
        read();

        cout << "Test: " << tc << '\n';

        solve();

        for(int i = 1; i <= n; i++)
        {
            g[i].clear();
            dep[i] = 0;
            dist[i] = 0;
            memset(up[i], 0, sizeof(up[i]));
        }
    }
}