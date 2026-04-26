#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;


const int N = 1e6;
int n,m;
int  dist[N] , ans[N];
vector < pair<int,int> > g[N];
priority_queue<pair<int, int> , vector< pair<int, int > >,greater<pair<int , int>> > q;
int own[N];
void read()
{
    cin >> n >> m;
    for(int i = 1 ;i <= n; ++i)
    {
        cin >> own[i];
    }
    /// đoạn này cạnh ngược vô nên kết quả ra đúng
    // móa 2 ngày của mình =))
    for(int i = 1 ; i <= m ; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        g[v].push_back({w,u});
    }
}
void dijkstra(int c)
{
    for(int i = 1 ; i <= n ; i++)
        dist[i] = 1e18;

    for(int i = 1 ; i <= n ; i++)
        if(own[i]==c)
        {
            dist[i] = 0;
            q.push({0,i});
        }



    while(!q.empty())
    {
        pair<int, int> u = q.top();
        q.pop();
        if (u.fi > dist[u.se])
            continue;
        for(auto v: g[u.se])
        {
            if(dist[v.se] > dist[u.se] + v.fi)
            {
                dist[v.se] = dist[u.se] + v.fi;
                q.push({dist[v.se],v.se});
            }
        }
    }

    for(int i = 1 ; i <= n ; i++)
        if(own[i] != c)
            ans[i] = dist[i];

}
void solve()
{
    dijkstra(0); /// tìm đáp án cho chẵn
    dijkstra(1); /// tìm đáp án cho lẽ

    for(int i = 1 ; i <= n ; i++)
    {
        if(ans[i] == 1e18)
            cout << "-1 " << "\n";
        else
            cout << ans[i] << "\n";
    }
}
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    read();
    solve();
    


}
