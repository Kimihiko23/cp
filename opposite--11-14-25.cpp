#include<bits/stdc++.h>
using namespace std;


const int N = 3e5 + 5;
int n;
int a[N] , dist[N] , ans[N];
vector < int > g[N];
queue < int > q;

void BFS(int c)
{
    for(int i = 1 ; i <= n ; i++)
        dist[i] = 1e9;

    for(int i = 1 ; i <= n ; i++)
        if((c + a[i]) % 2 == 1)
        {
            dist[i] = 0;
            q.push(i);
        }



    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v: g[u])
        {
            if(dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    for(int i = 1 ; i <= n ; i++)
        if(a[i] % 2 == c)
            ans[i] = dist[i];

}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n;
    /// đoạn này cạnh ngược vô nên kết quả ra đúng
    // móa 2 ngày của mình =))
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        if(i - a[i] >= 1)
            g[i - a[i]].push_back(i);
        if(i + a[i] <= n)
            g[i + a[i]].push_back(i);
    }

    BFS(0); /// tìm đáp án cho chẵn
    BFS(1); /// tìm đáp án cho lẽ

    for(int i = 1 ; i <= n ; i++)
    {
        if(ans[i] == 1e9)
            cout << "-1 ";
        else
            cout << ans[i] << " ";
    }


}
