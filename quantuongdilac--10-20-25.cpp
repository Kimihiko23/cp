#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=100;
int dem[N][N];
bool dd[N][N];
int stx, sty, enx, eny;
void bfs()
{
    queue<pair<int,int>> q;
    q.push({stx, sty});
    dd[stx][sty]=1;
    dem[stx][sty]=0;
    int dx[]={-2, -2,2,2};
    int dy[]={-2, 2,-2,2}; 
    while(!q.empty())
    {
        pair<int,int> u=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int xx=u.fi+dx[i];
            int yy=u.se+dy[i];
            if(xx>=1 && xx<=8 && yy>=1 && yy<=8 && !dd[xx][yy])
            {
                dd[xx][yy]=1;
                dem[xx][yy]=dem[u.fi][u.se]+1;
                q.push({xx, yy});
            }
        }
    }
    cout << dem[enx][eny];
}
void read()
{
    cin >> stx >> sty >> enx >> eny;
}

void solve()
{
    for(int i=1; i<=8; i++)
        for(int j=1; j<=8; j++)
        {
            dem[i][j]=-1, 
            dd[i][j]=0;
        }
    bfs();
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
