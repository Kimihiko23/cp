#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
int dist[N]={0},
distu1[N]={0},
distu2[N]={0};
vector<pair<int,int>> g[N];
vector<pair<int,int>> g1[N];
int n,m,u1,u2,u,v;
void dijkstra(int start)
{
    priority_queue < pair < int , int > ,
                 vector < pair < int , int > > ,
                 greater < pair < int , int > > > q;
    for(int i = 1 ; i <= n ; i++)
        dist[i] = 1e18;
    dist[start] = 0;
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
            }
        }
        
    }
    
}
void dijkstrau1(int start)
{
    priority_queue < pair < int , int > ,
                 vector < pair < int , int > > ,
                 greater < pair < int , int > > > q;
    for(int i = 1 ; i <= n ; i++)
        distu1[i] = 1e18;
    distu1[start] = 0;
    q.push({distu1[start] , start});
    
    
    /// (n + m) * log2(n)
    while(!q.empty())
    {
        int u = q.top().second;
        int cost = q.top().first;
        q.pop();
        if(cost > distu1[u])
            continue;
       
        for(auto e: g1[u])
        {
            int v = e.first;
            int w = e.second;
            if(distu1[v] > distu1[u] + w)
            {
                distu1[v] = distu1[u] + w;
                q.push({distu1[v] , v});
            }
        }
        
    }
    
}
void dijkstrau2(int start)
{
    priority_queue < pair < int , int > ,
                 vector < pair < int , int > > ,
                 greater < pair < int , int > > > q;
    for(int i = 1 ; i <= n ; i++)
        distu2[i] = 1e18;
    distu2[start] = 0;
    q.push({distu2[start] , start});
    
    
    /// (n + m) * log2(n)
    while(!q.empty())
    {
        int u = q.top().second;
        int cost = q.top().first;
        q.pop();
        if(cost > distu2[u])
            continue;
       
        for(auto e: g1[u])
        {
            int v = e.first;
            int w = e.second;
            if(distu2[v] > distu2[u] + w)
            {
                distu2[v] = distu2[u] + w;
                q.push({distu2[v] , v});
            }
        }
        
    }
    
}
void read()
{
    cin >> n >> m >> u1 >> u2 >> v;
    for(int i=1;i<=n;i++)
    {
        dist[i]=1e18;
        distu1[i]=1e18;
        distu2[i]=1e18;
    }
    for(int i=1;i<=m;i++)
    {
        int tam1,tam2,w;
        cin >> tam1 >> tam2 >> w;
        g[tam2].pb({tam1,w});
        g1[tam1].pb({tam2,w});
    }
}
void solve()
{
    dijkstra(v);
    dijkstrau1(u1);
    dijkstrau2(u2);
    int ans=1e18;
    for(int i=1;i<=n;i++)
    {
        ans=min(ans,dist[i]+distu1[i]+distu2[i]);
    }
    if(ans>=1e17)
    {
        cout << -1;

    }
    else
    cout << ans;
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //freopen("GAY.inp","r",stdin);
    //freopen("GAY.out","w",stdout);
    read();
    solve();
   
    
}
