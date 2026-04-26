#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 23;

int n, m;
vector<pair<int,int>> a[N];
int dist[N], pre[N];

void dijkstra(int source)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();

        if (du != dist[u]) continue;

        for (auto [v, w] : a[u])
        {
            if (dist[v] > du + w)
            {
                dist[v] = du + w;
                pre[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

void read()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back({v, 1});
        a[v].push_back({u, 1});
    }

    for (int i = 1; i <= n; i++)
    {
        dist[i] = LLONG_MAX;
        pre[i] = 0;
    }
}

void solve()
{
    dijkstra(1);
    if (dist[n] == LLONG_MAX)
    {
        cout << "IMPOSSIBLE";
        return;
    }

    vector<int> path;
    for (int t = n; t != 0; t = pre[t])
    {
        path.push_back(t);
        if (t == 1) break;
    }

    reverse(path.begin(), path.end());
    cout << path.size() << '\n';
    for (int x : path) cout << x << " ";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    read();
    solve();
}
