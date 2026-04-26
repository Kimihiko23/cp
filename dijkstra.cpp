#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 5;
int n , m;
int dist[N];
priority_queue < pair < int , int > ,
                 vector < pair < int , int > > ,
                 greater < pair < int , int > > > q;
                 
vector < pair < int , int > > g[N];

// /// lớn tới bé
// priority_queue < kiểu dữ liệu > pq;
// /// bé tới lớn
// priority_queue < kiểu dữ liệu,
//                  vector < kiểu dữ liệu > ,
//                  greater < kiêu dữ liệu > > pq;

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

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++)
    {
        int u , v , w;
        cin >> u >> v >> w;
        g[u].push_back({v , w});
        g[v].push_back({u , w});
    }
    dijkstra(1);
    
    if(dist[n] == 1e18)
        cout << "-1";
    else
        cout << dist[n];
    
    
}