#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6;
vector<int> canh[N]={};
vector<int> ans={};
bool dd[N];
int n,m;
void bfs(int st)
{
    queue<int> tt;
    tt.push(st);
    int dem=0;
    dd[st]=true;
    while(!tt.empty())
    {
        int u=tt.front();
        tt.pop();
        dem++;
        for(int i=0;i<canh[u].size();i++)
        {
            if (!dd[canh[u][i]])
            {
                tt.push(canh[u][i]);
                dd[canh[u][i]]=true;
            }
        }
        
        
    }
    ans.pb(dem);
 
}

void read()
{
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin >> u >> v;
        canh[u].pb(v);
        canh[v].pb(u);
    }
}

void solve()
{
    for(int i=1;i<=n;i++)
    {
        if (!dd[i])
        {
            bfs(i);
        }
    }
    sort(all(ans));
    cout << ans[ans.size()-1]+ans[ans.size()-2];
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
