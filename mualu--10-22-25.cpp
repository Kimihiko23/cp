#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6+5;
int n,m,x;
vector<int> canh[N];
bool dd[N];
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    dd[u]=1;
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for (auto v:canh[u])
        {
            if (!dd[v])
            {
                dd[v]=1;
                q.push(v);
            }
        }
    }
}
void read()
{
    cin >> n >> m >> x;
    for (int i=1;i<=m;i++)
    {
        int u,v,c;
        cin >> u >> v >> c;
        if (c>=x)
        {
            canh[u].pb(v);
            canh[v].pb(u);
        }
    }
}

void solve()
{
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        if (!dd[i])
        {
            ans++;
            bfs(i);
        }
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
