#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6+5;
int mn=1e18;
vector<pair<int,int>> canh[N];
int n,m,k;
bool dd[N];
void bfs(int st,int we)
{
    queue<int> tt;
    tt.push(st);
    dd[st]=true;
    while (!tt.empty())
    {
        int u=tt.front();
        tt.pop();
        for(int i=0;i<canh[u].size();i++)
        {
            if (canh[u][i].se>=we &&  !dd[canh[u][i].fi])
            {
                tt.push(canh[u][i].fi);
                dd[canh[u][i].fi]=true;

            }
        }

    }
}
void read()
{
    cin >> n >> m >> k;
    int tam;
    for(int i=1;i<=k;i++)
    {
        cin >> tam;
        mn=min(tam,mn);
    }
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        canh[u].pb({v,w});
        canh[v].pb({u,w});

    }
}

void solve()
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!dd[i])
        {
            bfs(i,mn);
            ans++;
        }
    }
    cout << ans;
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    read();
    solve();
    
   
}
