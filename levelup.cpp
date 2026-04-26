#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
map<int,vector<pair<int,int>>> g;
int st,ed;
map<int, pair<int,int>> power;
map<int,int> dist;
int n,m;
void dijsktra(int st)
{
    priority_queue<pair<int, pair< int, int>>, vector< pair <int, pair<int ,int >>>, greater < pair <int, pair<int ,int >>>> pq;
    pq.push({st,{0,0}});
}
void read()
{
    cin >> n >> m >> st >> ed;
    for(int i=1; i <= m; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    for(int i=1; i <=n ;i++)
    {
        int po,sle;
        cin >> po >> sle;
        power[i] = {po,sle};
    }
    
}
void solve()
{
    
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
