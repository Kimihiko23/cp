#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
int n , m , mod = 11;
int dist[N];
vector < pair < int , int > > g[N];


vector < int > ve[11];




void dial(int start)
{
    for(int i = 1 ; i <= n ; i++)
        dist[i] = 1e9;
    dist[start] = 0;

    ve[0].push_back(start);

    for(int w = 0 ; w <= 10 * n ; w++)
    {
        while(!ve[w % mod].empty())
        {
            int u = ve[w % mod].back();
            ve[w % mod].pop_back();

            if(w > dist[u])
                continue;

            for(auto e: g[u])
            {
                int v = e.first;
                int w = e.second;
                if(dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    ve[dist[v] % mod].push_back(v);
                }
            }
        }
    }
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++)
    {
        int u , v , w;
        cin >> u >> v >> w;
        g[u].push_back({v , w});
        g[v].push_back({u , w});
    }

    dial(1);


    cout << dist[n];

}
