#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
vector<pair<int,int>> canh1[N];
vector<pair<int,int>> canh[N];
bool dd[N]={0};
int dis[N];
int dis1[N];
int n,m,k,s,t;
void dij1(int st)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> tt;
    tt.push({0,st});
    dis[st]=0;

    while(!tt.empty())
    {
        int u=tt.top().se;
        //u la dinh dang xet
        int w=tt.top().fi;
        //w la khoang cach tu dinh st den u
        tt.pop();
        if (w > dis[u]) continue;

        for(int i=0;i<canh[u].size();i++)
        {
            if (dis[canh[u][i].se]==1e18 || dis[canh[u][i].se]>w+canh[u][i].fi)
            {
                dis[canh[u][i].se]=w+canh[u][i].fi;
                tt.push({dis[canh[u][i].se],canh[u][i].se});
            }
        }
    }
}
void dij2(int st)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> tt;
    tt.push({0,st});
    dis1[st]=0;
  
    while(!tt.empty())
    {  
        int u=tt.top().se;
        //u la dinh dang xet
        int w=tt.top().fi;
        //w la khoang cach tu dinh st den u
        tt.pop();
        if (w > dis1[u]) continue;

        for(int i=0;i<canh1[u].size();i++)
        {
            if (dis1[canh1[u][i].se]==1e18 || dis1[canh1[u][i].se]>w+canh1[u][i].fi)
            {
                dis1[canh1[u][i].se]=w+canh1[u][i].fi;
                tt.push({dis1[canh1[u][i].se],canh1[u][i].se});
            }
        }
    }
}
int q;
void read()
{
    cin >> n >> m >> k >> s >> t;
    
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        canh[u].pb({w,v});
        canh1[v].pb({w,u});
    }
}
void solve()
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=1e18;
        dis1[i]=1e18;
    }
    dij1(s);
    dij2(t);
    int ans=dis[t];
    for(int i=1;i<=k;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        ans=min({ans,dis[u]+dis1[v]+w,dis[v]+dis1[u]+w});  
    }
    if(ans>1e17) ans=-1;
    cout << ans << "\n";
    for(int i=1;i<=n;i++)
    {
        canh1[i].clear();
        canh[i].clear();
    }
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> q;
    while(q--)
    {
    read();
    solve();
    }
   
    
}
