#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
int n,m;
int st1,ed1,k;
int dist[N];
vector<pair<int,int>> edge[N];
bool bfs01(int st ,int ed, int w)
{
    
    //minimum ticket to go to i
    for(int i=1;i<=n;i++)
    {
        dist[i]=1e18;
    }
    dist[st]=0;
    deque<int> tt;
    tt.push_back(st);
    while(!tt.empty())
    {
        int u=tt.front();
        tt.pop_front();
        for(int i=0; i <edge[u].size();i++)
        {
            if (edge[u][i].se>w && dist[edge[u][i].fi]>dist[u]+1)
            {
                dist[edge[u][i].fi]=dist[u]+1;
                tt.push_back(edge[u][i].fi);
            }
            else
            if(edge[u][i].se<=w && dist[edge[u][i].fi]>dist[u]+0)
            {
                dist[edge[u][i].fi]=dist[u];
                tt.push_front(edge[u][i].fi);
            }
        }
    }
    if (dist[ed]>k)
    return false;
    else
    return true;

}
void read()
{
    cin >> n >> m;
    for(int i=1; i<=m; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        edge[u].pb({v,w});
        edge[v].pb({u,w});
    }
}

void solve()
{
    cin >>  st1 >> ed1 >> k;
    int l=0,r=1e9,mid;
    int ans=1e18;
    mid=(l+r)/2;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(bfs01(st1,ed1,mid))
        {
            r=mid-1;
            ans=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    cout << ans << "\n";
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    read();
    int q;
    cin >> q;
    while(q--)
    solve();
   
    
}
