#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
int n,m;
vector<pair<int,int>> rev_g[N];
vector<pair<int,int>> g[N];
vector<tuple<int,int,int>> canh;
int dist[N],rev_dist[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
void dijkstra(int start)
{
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
void rev_dijkstra(int start)
{
    for(int i = 1 ; i <= n ; i++)
        rev_dist[i] = 1e18;
    rev_dist[start] = 0;
    q.push({rev_dist[start] , start});
    
    
    /// (n + m) * log2(n)
    while(!q.empty())
    {
        int u = q.top().second;
        int cost = q.top().first;
        q.pop();
        if(cost > rev_dist[u])
            continue;
       
        for(auto e: rev_g[u])
        {
            int v = e.first;
            int w = e.second;
            if(rev_dist[v] > rev_dist[u] + w)
            {
                rev_dist[v] = rev_dist[u] + w;
                q.push({rev_dist[v] , v});
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
        g[u].push_back({v,w});
        rev_g[v].push_back({u,w});
        canh.push_back(make_tuple(u,v,w));
        //cout << get<0>(canh[i-1]) << " " << get<1>(canh[i-1]) << " " << get<2>(canh[i-1]) << "\n";
    }
    
}
void solve()
{
    dijkstra(1);
    while(!q.empty()) q.pop();

    rev_dijkstra(2);
    int ans=dist[2];
    for(int i=1;i<=m;i++)
    {
        int tam=dist[get<1>(canh[i-1])]+rev_dist[get<0>(canh[i-1])]+get<2>(canh[i-1]);
        if (tam<ans)
        {
            cout << "TAN\n";
        }
        else
        if(tam==ans || dist[get<0>(canh[i-1])] + get<2>(canh[i-1]) + rev_dist[get<1>(canh[i-1])] > ans)
        {
            cout << "DEP\n";
        }
        else
        {
            cout<<"TRAI\n";
        }
    }
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
