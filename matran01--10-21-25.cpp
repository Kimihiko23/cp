#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n , m , K , cnt_1;
int dist[N][N];
int a[N][N];
int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};
queue < pair < int , int > > q;
pair < int , int > start;


void BFS(pair < int , int > start)
{

    for(int i = 1 ; i <= n ; i++)
    	for(int j = 1 ; j <= m ; j++)
            dist[i][j] = 1e9;

    int cnt = 0;


    dist[start.first][start.second] = 0;
    cnt++;
    if(cnt == cnt_1 - K)
    	 return;
    q.push(start);

    while(!q.empty())
    {
        int u = q.front().first;
	    int v = q.front().second;
        q.pop();
        ///cout << u << " " << v << " " << dist[u][v] << endl;
    	for(int k = 0 ; k <= 3 ; k++)
    	{
    	    int x = u + dx[k];
    	    int y = v + dy[k];
    	    if(x > 0 && x <= n && y > 0 && y <= m
    	     &&   a[x][y] == 1
    	     &&   dist[x][y] > dist[u][v] + 1)
    	    {
    	        dist[x][y] = dist[u][v] + 1;
    	        cnt++;

    	        if(cnt == cnt_1 - K)
    	            return;
    	        q.push({x , y});
    	    }
        }
    }
}


main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> K;

    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 1)
            {
                cnt_1++;
                start = {i , j};
            }
        }

    BFS(start);


    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            if(a[i][j] == 1 && dist[i][j] == 1e9)
                cout << i << " " << j << "\n";



}