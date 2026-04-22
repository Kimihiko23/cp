#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e4+23;
int n,m;
int k;
vector<pair<int,pair<int,int>>> g[N];
int dist[200][N];
void dij(int st)
{
    priority_queue<pair<int,pair<int,int>>,
                    vector<pair<int,pair<int,int>>>,
                    greater<pair<int,pair<int,int>>>> tt;
    dist[st][k]=0;
    // tt: {dist,{node,money_left}}
    tt.push({0,{st,k}});
    while(!tt.empty())
    {
        int u=tt.top().se.fi;
        int money=tt.top().se.se;
        int s=tt.top().fi;
        tt.pop();
        if(s>dist[u][money])
            continue;
        for(int i=0;i<g[u].size();i++)
        {
            if (money-g[u][i].se.se>=0 && dist[g[u][i].se.fi][money-g[u][i].se.se]>dist[u][money]+g[u][i].fi)
            {
                dist[g[u][i].se.fi][money-g[u][i].se.se]=dist[u][money]+g[u][i].fi;
                tt.push({dist[g[u][i].se.fi][money-g[u][i].se.se],{g[u][i].se.fi,money-g[u][i].se.se}});
            }
        }

    }
    
}
void read()
{
    cin >> k;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        g[i].clear();
    }
    for(int i=1;i<=m;i++)
    {
        int u,v,w,c;
        cin >> u >> v >> w >> c;
        g[u].pb({w,{v,c}});
        //g[v].pb({w,{u,c}});

    }
}

void solve()
{
    for(int i=1;i<=n;i++)
    for(int j=0;j<=k;j++)
    //wrong at j=1 but right must be j=0
    {
        dist[i][j]=1e18;
        //g[i].clear();
    }
    dij(1);
    int ans=1e18;
    for(int i=0;i<=k;i++)
    {
        ans=min(ans,dist[n][i]);
    }
    if(ans>=1e17)
    {
        cout << "-1\n";
    }
    else
    {
        cout << ans<< "\n";
    }
    
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
    read();
    solve();
    }
    
   
}
