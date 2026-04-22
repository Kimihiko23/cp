
#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6;
int n,m;
vector<int> canh[N];
bool dd1[N]={0};
int kc1[N]={0};
bool dd2[N]={0};
int kcn[N]={0};
void bfs1()
{

    queue<int> q;
    q.push(1);
    dd1[1]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int i=0;i<canh[u].size();i++)
        {
            if (!dd1[canh[u][i]])
            {
                dd1[canh[u][i]]=true;
                kc1[canh[u][i]]=kc1[u]+1;
                q.push(canh[u][i]);
            }
            else
            {
                kc1[canh[u][i]]=min(kc1[u]+1,kc1[canh[u][i]]);
            }
        }
    }
    
}
void bfs2()
{

    queue<int> q;
    q.push(n);
    dd2[n]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int i=0;i<canh[u].size();i++)
        {
            if (!dd2[canh[u][i]])
            {
                dd2[canh[u][i]]=true;
                kcn[canh[u][i]]=kcn[u]+1;
                q.push(canh[u][i]);
            }
            else
            {
                kcn[canh[u][i]]=min(kcn[u]+1,kcn[canh[u][i]]);
            }
        }
    }
    
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
    bfs1();
    bfs2();
    for(int i=1;i<=n;i++)
    {
        if(dd1[i] && dd2[i])
        {
            cout << kcn[i]+kc1[i]<< " ";
        }
        else
        {
            cout << -1 << " ";
        }
    }
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
