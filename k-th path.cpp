#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =2e5+23;
int n,m,k;
vector<pair<int,pair<int,int>>> edge_remain;
vector<pair<int,int>> edge[N];
vector<int> ans;
int dist[N];

void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    
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
       
        for(auto e: edge[u])
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

void read()
{
    cin >> n >>m >>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        edge_remain.pb({w,{u,v}});
    }

}

void solve()
{
    set<int> needed;
    sort(edge_remain.begin(),edge_remain.end());
    for(int i=0;i<min(m,k);i++)
    {
        edge[edge_remain[i].se.fi].pb({edge_remain[i].se.se,edge_remain[i].fi});
        edge[edge_remain[i].se.se].pb({edge_remain[i].se.fi,edge_remain[i].fi});
        needed.insert(edge_remain[i].se.fi);
        needed.insert(edge_remain[i].se.se);
    }
    edge_remain.clear();
    for(auto i:needed)
    {
        dijkstra(i);
        //not include from i to i and (i to j)  or (j to i) only cout as 1 way
        for(int j=i+1;j<=n;j++)
        {
            if(dist[j]<=1e17)
            ans.push_back(dist[j]);
        }
    }
    /*for(auto e:edge_remain)
    {
        cout<< e.se.fi << " " << e.se.se << " " << e.fi << "\n";
    }*/
    sort(ans.begin(),ans.end());
    int sz=ans.size()-1;
    cout << ans[min(sz,k-1)];
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
