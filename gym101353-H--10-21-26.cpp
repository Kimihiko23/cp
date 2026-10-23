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
const int N = 1e5 + 23;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int NINF = -1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r) 
{
    return uniform_int_distribution<int>(l, r)(rng);
}
int flor(int a, int b)
{
    return a / b - (a % b && (a ^ b) < 0);
}
vector<int> dx{0, 0, 1, -1}, dy{-1, 1, 0, 0};

int n, ans;
vector<pair<int, int>> g[N];
int sz[N], A[N], B[N];

void dfs(int u, int p)
{
    sz[u] = 1;
    A[u] = B[u] = 0;
    for(auto i : g[u])
    {
        int v = i.fi, w = i.se;
        if(v == p)
            continue;
        dfs(v, u);
        sz[u] += sz[v];
        int s = sz[v] % MOD;
        A[u] = (A[u] + A[v] + w % MOD * s) % MOD;
        B[u] = (B[u] + B[v] + w % MOD * s % MOD * s) % MOD;
    }
    int f = ((sz[u] % MOD) * A[u] % MOD - B[u] + MOD) % MOD;
    ans = (ans + f) % MOD;
}

void read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        g[i].clear();
    for(int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
}
void solve()
{
    ans = 0;
    dfs(1, 0);
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
    // freopen(name ".inp", "r", stdin);
    // freopen(name ".out", "w", stdout);
    
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        read();
        solve();
        cout << "Case " << tc << ": " << ans << "\n";
    }
}