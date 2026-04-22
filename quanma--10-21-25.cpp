#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=2023;
int stx, sty, enx, eny;
int dem[N][N];
bool dd[N][N];
int n,m;
void bfs()
{
    queue<pair<int,int>> q;
    q.push({stx, sty});
    dd[stx][sty]=1;
    dem[stx][sty]=0;
    int dx[]={-2,-1, 1, 2,-2,-1, 1,2};
    int dy[]={-1,-2,-2,-1,1 ,2 ,2,1}; 
    while(!q.empty())
    {
        pair<int,int> u=q.front();
        q.pop();
        for(int i=0; i<8; i++)
        {
            int xx=u.fi+dx[i];
            int yy=u.se+dy[i];
            if(xx>=1 && xx<=n && yy>=1 && yy<=m && !dd[xx][yy])
            {
                dd[xx][yy]=1;
                dem[xx][yy]=dem[u.fi][u.se]+1;
                q.push({xx, yy});
            }
        }
    }
}
void read()
{
    cin >> n >> m;
    cin >> stx >> sty >> enx >> eny;
}

void solve()
{
    bfs();
    if (dd[enx][eny] == 0) {
        cout << -1;
    }
    else {
        cout << dem[enx][eny];
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
