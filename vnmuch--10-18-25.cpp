#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=200+5;
int n,m;
char a[N][N];
bool visited[N][N];
int dem[N][N]={0};
int stx,sty, enx, eny;
void bfs(int x, int y)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y]=1;
    int dx[]={-1,1,0,0};
    int dy[]={0,0,-1,1};
    while (!q.empty())
    {
        pair<int,int> u=q.front();
        q.pop();
        for (int i=0; i<4; i++)
        {
            int xx=u.fi+dx[i];
            int yy=u.se+dy[i];
            if (xx<1 || xx>n || yy<1 || yy>m) continue;
            if (a[xx][yy]=='*' || visited[xx][yy]) continue;
            dem[xx][yy]=dem[u.fi][u.se]+1;
            visited[xx][yy]=1;
            q.push({xx,yy});
        }
    }
    if (dem[enx][eny]==0) cout << -1;
    else cout << dem[enx][eny];
}
void read()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            cin >> a[i][j];
            visited[i][j]=0;
            if (a[i][j]=='C')
            {
                stx=i;
                sty=j;
            }
            if (a[i][j]=='B')
            {
                enx=i;
                eny=j;
            }
        }
    }
}

void solve()
{
    bfs(stx,sty);
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
