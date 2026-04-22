#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
bool dd[N]={true};
vector<int> a[N];
queue<int> q;
int n,m,s,t;
bool dd1=true;
int dem[N]={0};
void bfs(int st,int ed)
{
    q.push(st);
    dd[st]=false;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if (u==ed)
        {
            dd1=false;
            break;
        }
        for (auto v:a[u])
        {
            if (dd[v])
            {
                dem[v]=dem[u]+1;
                dd[v]=false;
                q.push(v);
            }
        }
    }
}
void read()
{
    cin >> n >> m >> s >> t;
    for(int i=1;i<=n;i++) dd[i]=true;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}
void solve()
{
    bfs(s,t);
    if (dd1) 
    cout << -1;
    else{
        cout << dem[t] << "\n";
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
