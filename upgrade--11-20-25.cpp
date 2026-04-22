#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =2e5+23;
const int mod=1e9+7;
int n,m;
int dist[N];
int distn[N];
vector<pair<int,int>> g[N];
int ways1[N];
int waysn[N];
tuple<int,int,int> edges[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
void dijkstra1(int start)
{
    for(int i = 1 ; i <= n ; i++)
    {
        dist[i] = 1e18;
        ways1[i]=0;
    }
    dist[start] = 0;
    ways1[start]=1;
    q.push({dist[start] , start});
    
    
    /// (n + m) * log2(n)
    while(!q.empty())
    {
        int u = q.top().second;
        int cost = q.top().first;
        q.pop();
        if(cost > dist[u])
            continue;
       
        for(auto e: g[u])
        {
            int v = e.first;
            int w = e.second;
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                q.push({dist[v] , v});
                ways1[v]=ways1[u];
            }
            else
            if(dist[v] == dist[u] + w)
            {
                ways1[v]=(ways1[v]+ways1[u])%mod;
            }
            
        }
        
    }
    
}
void dijkstran(int start)
{
    for(int i = 1 ; i <= n ; i++)
    {
        distn[i] = 1e18;
        waysn[i]=0;
    }
    distn[start] = 0;
    waysn[start]=1;
    q.push({distn[start] , start});
    
    
    /// (n + m) * log2(n)
    while(!q.empty())
    {
        int u = q.top().second;
        int cost = q.top().first;
        q.pop();
        if(cost > distn[u])
            continue;
       
        for(auto e: g[u])
        {
            int v = e.first;
            int w = e.second;
            if(distn[v] > distn[u] + w)
            {
                distn[v] = distn[u] + w;
                q.push({distn[v] , v});
                waysn[v]=waysn[u];
            }
            else
            if(distn[v] == distn[u] + w)
            {
                waysn[v]=(waysn[v]+waysn[u])%mod;
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
        g[u].pb({v,w});
        g[v].pb({u,w});
        edges[i]={u,v,w};
    }
}
void solve()
{
    bool dd[n+23];
    dijkstra1(1);
    while(!q.empty()) q.pop();
    dijkstran(n);
    for(int i=1;i<=n;i++) dd[i]=false;
    vector<int> ans;
    int dem=0;
    for(int i=1;i<=m;i++)
    {
        //cout << get<0>(edges[i]) << " " << get<1>(edges[i]) << " " << get<2>(edges[i]) << "\n";
        if((dist[n]==get<2>(edges[i])+dist[get<0>(edges[i])]+distn[get<1>(edges[i])] && (ways1[get<0>(edges[i])]*waysn[get<1>(edges[i])])%mod==ways1[n])
    || (dist[n]==get<2>(edges[i])+dist[get<1>(edges[i])]+distn[get<0>(edges[i])] && (ways1[get<1>(edges[i])]*waysn[get<0>(edges[i])])%mod==ways1[n]))
        {
            dem++;
        }
    
    }
    cout << dem;
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    read();
    solve();

   
    
}