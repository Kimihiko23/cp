/// code sai cmn r ;((
#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e6+23;
bool dd[N];
vector<int> g[N];
int n,m,d;
int dist1[N];
int dist[N];
int mn;
void dijkstra1(int st)
{
    priority_queue<pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>> q;
    dist1[st]=dd[st];
    q.push({dist1[st],st});
    while(!q.empty())
    {
        int u=q.top().se;
        int w=q.top().fi;
        q.pop();
        if(dist1[u]>w)
        {
            continue;
        }
        for(auto i: g[u])
        {
            if(dist1[i]>dd[i]+w)
            {
                dist1[i]=dd[i]+w;
                q.push({dist1[i],i});
            }
        }
    }
    mn = dist1[n];
}
void dijkstra(int st)
{
    priority_queue<pair<int, pair<int, int>>,
    vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>> q;
    dist[st]=0;
    q.push({dist[st],{dd[st],st}});
    while(!q.empty())
    {
        int u=q.top().se.se;
        int w=q.top().fi;
        int check=q.top().se.fi;
        q.pop();
        if(u==n)
        {
            break;
        }
        if(dist[u]<w)
        {
            continue;
        }
        for(auto i: g[u])
        {
            if(check+dd[i]<=mn && dist[i]>w+1)
            {
                dist[i]=w+1;
                q.push({dist[i],{check+dd[i],i}});
            }
        }

    }
    cout << dist1[n] << " " << dist[n];
}
/*struct Node {
    int dist, check, u;
    bool operator>(const Node& other) const {
        return dist > other.dist;   // CHỈ xếp theo dist
    }
};

void dijkstra(int st) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    dist[st] = 0;
    pq.push({0, dd[st], st});

    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int u = cur.u, w = cur.dist, c = cur.check;

        if (w > dist[u]) continue;

        for (int v : g[u]) {
            int nc = c + dd[v];
            if (nc > mn) continue;   // LỌC Ở ĐÂY

            if (dist[v] > w + 1) {
                dist[v] = w + 1;
                pq.push({dist[v], nc, v});
            }
        }
    }
    cout << dist1[n] << " " << dist[n];
}*/

void read()
{
    int tam;
    cin >> n >> m >> d;
    for(int i=1;i <= n; i++)
    {
        dd[i]=false;
        dist1[i]=1e18;
        dist[i]=1e18;
    }
    for(int i=1;i <= d; i++)
    {
        cin >> tam;
        dd[tam]=true;
    }
    for(int i=1;i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
}
void solve()
{
    dijkstra1(1);
    dijkstra(1);
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
