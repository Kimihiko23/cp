#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=2000;
int n,m;
vector<pair<int,int>> canh[N];
int bfs(int w)
{
    bool dd[N]={0};
    queue<int> q;
    q.push(1);
    dd[1]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int i=0;i<canh[u].size();i++)
        {
            if (canh[u][i].se>=w && !dd[canh[u][i].fi])
            {
                dd[canh[u][i].fi]=true;
                q.push(canh[u][i].fi);
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if (!dd[i])
            cnt++;
    }
    return cnt;
}
void read()
{
    cin >> n >> m;
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
    int l=0,r=1200;
    int ans=1e18;
    while(l<=r)
    {
        int mid=(l+r)/2;
        int res = bfs(mid);
            if (res > 0) 
    {
        ans = mid;
        r = mid - 1;
    }
    else 
        l = mid + 1;
          


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
