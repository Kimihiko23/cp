#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N = 1e3 + 5;
int n , test , x , y;
int dist[N][N];
int a[N][N];
pair < int , int > fin;
int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};
queue < pair < int , int > > q;
pair < int , int > start;
bool dd[N][N];
void BFS(pair < int , int > start)
{

    for(int i = 1 ; i <= n ; i++)
    	for(int j = 1 ; j <= n ; j++)
            dist[i][j] = 1e9;

    dist[start.first][start.second] = 0;
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
    	    if(x > 0 && x <= n && y > 0 && y <= n
    	     &&  __gcd(a[x][y] , a[u][v]) == 1
    	     &&   dist[x][y] > dist[u][v] + 1)
    	    {
    	        dist[x][y] = dist[u][v] + 1;
    	        q.push({x , y});
    	    }
        }
    }
}
void create() 
{
    int x = 1, y = 1;
    int dem = 1;
    int tt = 1; 
    a[x][y] = dem;
    dd[x][y] = true;

    while (dem < n * n) {
        if (tt == 1) { 
            if (y + 1 > n || dd[x][y + 1]) { tt = 2; continue; }
            y++;
        } else if (tt == 2) { 
            if (x + 1 > n || dd[x + 1][y]) { tt = 3; continue; }
            x++;
        } else if (tt == 3) { 
            if (y - 1 < 1 || dd[x][y - 1]) { tt = 4; continue; }
            y--;
        } else if (tt == 4) { 
            if (x - 1 < 1 || dd[x - 1][y]) { tt = 1; continue; }
            x--;
        }

        dem++;
        a[x][y] = dem;
        dd[x][y] = true;
    }
}
void rebuild()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            dd[i][j]=false;
    }
}
int t;
int st,ed;
void read()
{
    cin >> t;
}

void solve()
{
    while(t--)
    {
        rebuild();
        cin >> n >> st >> ed;
        create();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if (a[i][j]==st)
                {
                    start={i,j};
                }
                if (a[i][j]==ed)
                {
                    fin={i,j};
                }
            }
        }
        BFS(start);
        cout << dist[fin.first][fin.second] << "\n";

    }
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    solve();

    
}
