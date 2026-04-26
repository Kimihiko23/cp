#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e6+23;
int kq[N];
int n,m,k;
vector<int> g[N],revg[N];
bool ddg[N],ddrevg[N];
int demghe[N];
void bfs(int st,int ed)
{
    queue<int> q;
    q.push(st);
    for(int i=1;i<=n;i++)
    {
        ddg[i]=false;
    }   
    ddg[st]=true;
    while(!q.empty())
    {
        int u=q.front();
        
        q.pop();
        if(u==ed) continue;
        //k di duoc qua u nen continue
        for(int i : g[u])
        {
            if (!ddg[i])
            {
                ddg[i]=true;
                q.push(i);
            }
        }
       

    }
}
void rbfs(int st,int ed)
{
    queue<int> q;
    q.push(st);
    for(int i=1;i<=n;i++)
    {
        ddrevg[i]=false;   
    }   
    ddrevg[st]=true;

    while(!q.empty())
    {
        int u=q.front();
        
        q.pop();
        if(u==ed) continue;
        //k di duoc qua u nen continue
        for(int i : revg[u])
        {
            if (!ddrevg[i])
            {
                ddrevg[i]=true;
                q.push(i);
            }
        }
       
    }
}
void read()
{
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        revg[v].pb(u);
    }
}
void solve()
{
    for(int i=1;i<=k;i++)
    {
        int u,v;
        cin >> u >> v;
        bfs(u,v);
        rbfs(v,u);
        for(int j=1;j<=n;j++)
        {
            if (ddg[j] && ddrevg[j])
            {
                demghe[j]++;
            }
        }
    }
    int ans=0;
    vector<int> res;
    for(int i=1;i<=n;i++)
    {
        if (demghe[i]==k)
        {
            ans++;
            res.pb(i);
        }
        
    }
    cout << ans << "\n";
    for(int i:res)
    {
        cout << i << " ";
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
