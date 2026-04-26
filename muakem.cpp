#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
int n,m,k,x;
vector<pair<int,int>> g[N];
int distst[N];
int disted[N];
vector<int> seller;
int st,ed;
void dijkstraed(int str)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,str});
    for(int i=1;i<=n;i++)
    {
        disted[i]=1e18;
    }
    disted[str]=0;
    while(!q.empty())
    {
        int u=q.top().se;
        int w=q.top().fi;

        q.pop();
        if(disted[u]<w)
        {
            continue;
        }
        for(int i=0;i<g[u].size();i++)
        {
            if(disted[g[u][i].fi] > disted[u] + g[u][i].se)
            {
                disted[g[u][i].fi]= disted[u] + g[u][i].se;
                q.push({disted[g[u][i].fi],g[u][i].fi});
            }
        }
    }
    
}
void dijkstra(int str)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,str});
    for(int i=1;i<=n;i++)
    {
        distst[i]=1e18;
    }
    distst[str]=0;
    while(!q.empty())
    {
        int u=q.top().se;
        int w=q.top().fi;

        q.pop();
        if(distst[u]<w)
        {
            continue;
        }
        for(int i=0;i<g[u].size();i++)
        {
            if(distst[g[u][i].fi] > distst[u] + g[u][i].se)
            {
                distst[g[u][i].fi]= distst[u] + g[u][i].se;
                q.push({distst[g[u][i].fi],g[u][i].fi});
            }
        }
    }
    
}
void read()
{
    cin >> n >> m >> k >> x;
    for(int i = 1 ;i <= k ; i++)
    {
        int tam;
        cin >> tam;
        seller.pb(tam);
    }
    for(int i = 1; i <= m ; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    cin >> st >> ed;
}
void solve()
{
    dijkstra(st);
    dijkstraed(ed);
    int mn=1e18;
    for(int i=0; i < seller.size() ; i++)
    {
        if (distst[seller[i]] + disted[seller[i]] <= x)
        {
            mn=min(mn,distst[seller[i]] + disted[seller[i]]);
        }
    }
    cout << (mn == 1e18 ? -1 : mn);
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    read();
    solve();

   
    
}
