#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n , m;
int dist[N][N][9];
int a[N][N];
int dx[] = {-1 , -1 , -1 , 0 , 0 , 1 , 1 , 1};
int dy[] = {-1 , 0 , 1 , -1 , 1 , -1 , 0 , 1};
queue < pair < int , pair < int , int > > > q;
pair < int , int > start , fin;

bool inside(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

void BFS(pair < int , int > start)
{
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            for(int k = 0 ; k <= 7 ; k++)
                dist[i][j][k] = 1e9;

    dist[start.first][start.second][8] = 0;
    q.push({8 , start});

    while(!q.empty())
    {
        int u = q.front().second.first;
        int v = q.front().second.second;
        int k = q.front().first;
        q.pop();

        if(u == fin.first && v == fin.second)
        {
            cout << dist[u][v][k];
            return;
        }

        for(int new_k = 0 ; new_k <= 7 ; new_k++)
            if(new_k != k)
            {
                int x = u + dx[new_k] * a[u][v];
                int y = v + dy[new_k] * a[u][v];

                // ✅ added bounds check here
                if (!inside(x, y)) continue;

                if(dist[x][y][new_k] > dist[u][v][k] + 1)
                {
                    dist[x][y][new_k] = dist[u][v][k] + 1;
                    q.push({new_k , {x , y}});
                }
            }
    }
    cout << "-1";
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            cin >> a[i][j];
    
    start = {1 , 1};
    fin = {n , m};
    
    BFS(start);
}
