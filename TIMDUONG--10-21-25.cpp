#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N =1e5+23;
int n,q;
int a[N]={0};

vector<int> canh[N];

int x,k;
int ans=1e18;
void bfs(int u)
{
    bool visited[N]={0};
    visited[u]=1;
    queue<int> q;
    int tong[N]={0};
    int dem[N]={0};
    q.push(u);
    tong[u]=a[u];
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto v: canh[node])
        {
            if(!visited[v])
            {
                visited[v]=1;
                tong[v]=tong[node]+a[v];
                dem[v]=dem[node]+1;
                if(tong[v]>=k)
                {
                    ans=min(ans,dem[v]);
                }
                q.push(v);
            }
        }
    }
}
void read()
{
    cin >> n >> q;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        canh[u].pb(v);
        canh[v].pb(u);
    }
    
    
}
void solve()
{
    while(q--)
    {
        cin >> x >> k;
        ans=1e18;
        bfs(x);
        if(ans==1e18)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << ans << "\n";
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
