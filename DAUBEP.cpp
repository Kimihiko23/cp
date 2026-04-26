#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e4+23;
vector<int> canh[N];
int t;
int n,h,q,e;
bool dd[N]={0};
bool dd1[N]={0};
void bfs(int st)
{
    queue<int> tt;
    dd[st]=true;
    tt.push(st);
    while(!tt.empty())
    {
        int u=tt.front();
        tt.pop();
    
        for(int i=0;i<canh[u].size();i++)
        {
            if(!dd[canh[u][i]])
            {
                tt.push(canh[u][i]);
                dd[canh[u][i]]=true;
            }
        }
    }
}
void read()
{
    cin >> t;
}
void solve()
{
    cin >> n >> h >> e >> q;
    for(int i=1;i<=n;i++)
    {
        dd[i]=false;
        canh[i].clear();
        dd1[i]=false;
    }
    for(int i=1;i<=e;i++)
    {
        int u,v;
        cin >> u >> v;
        canh[u].pb(v);
        canh[v].pb(u);
    }
    int z;
    for(int i=1;i<=q;i++)
    {
        cin >> z;
        for(int j=1;j<=z;j++)
        {
            int tam;
            cin >> tam;
            dd1[tam]=true;
        }

    }
    bfs(h);
    for(int i=1;i<=n;i++)
    {
        if (dd1[i] && !dd[i])
        {
            cout << "NO\n";
            return;
        }
    }
    cout<< "OK\n";

}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("DAUBEP.inp","r",stdin);
    // freopen("DAUBEP.out","w",stdout);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    read();
    while(t--)
    {


        solve();
    }

}
