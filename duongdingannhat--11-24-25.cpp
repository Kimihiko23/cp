#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6;
int n,m;
vector<pair<int,int>> a[N];
int f[N];
int mn[N];
int mx[N];
int dist[N];
void dijkstra(int st)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,st});
    for(int i=1;i<=n;i++)
    {
        f[i]=0;
        mn[i]=1e18;
        mx[i]=-1e18;
        dist[i]=1e18;
    }
    dist[st]=0;
    mn[st]=0;
    mx[st]=0;
    f[st]=1;
    while(!q.empty())
    {
        int u=q.top().se;
        int wu=q.top().fi;
        q.pop();
        if(wu>dist[u]) continue;
        for(int i=0;i<a[u].size();i++)
        {
            int v=a[u][i].fi;
            int w=a[u][i].se;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                f[v]=f[u];
                mn[v]=mn[u]+1;
                mx[v]=mx[u]+1;
                q.push({dist[v],v});
            }
            else if(dist[v]==dist[u]+w)
            {
                f[v]=(f[v]+f[u])%1000000007;
                mn[v]=min(mn[v],mn[u]+1);
                mx[v]=max(mx[v],mx[u]+1);
            }
        }
    }

}
void read()
{
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        a[u].push_back({v,w});
    }
}

void solve()
{
    dijkstra(1);
    if(dist[n]!=1e18)
    cout << dist[n] << " " << f[n] << " " << mn[n] << " " << mx[n];
    else
    cout << -1;
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
