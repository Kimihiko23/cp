#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =2000;
int n,m;
int a[N][N]={0};
bool dd[N][N]={0};
int dis[N][N]={0};
int stx,sty;
bool check(int x,int y)
{
    if(x>=1 && x<=n && y>=1 && y<=m)
        return true;
    return false;
}
void bfs()
{
    queue<pair<int,int>> tt;
    tt.push({stx,sty});
    vector<int> dx{1,-1,0,0};
    vector<int> dy{0, 0,1,-1};
    dis[stx][sty]=0;
    while(!tt.empty())
    {
        pair<int,int> u=tt.front();
        tt.pop();
        for(int i=0;i<dx.size();i++)
        {
            if(check(u.fi+dx[i],u.se+dx[i]) && a[u.fi+dx[i]][u.se+dy[i]]==0 && 
                dis[u.fi+dx[i]][u.se+dy[i]]>dis[u.fi][u.se]+1)
            {
                dis[u.fi+dx[i]][u.se+dy[i]]=dis[u.fi][u.se]+1;
                tt.push({u.fi+dx[i],u.se+dy[i]});
            }
        }

    }
}

void read()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
            if(a[i][j]==2)
            {
                stx=i;
                sty=j;
            }
            dis[i][j]=1e18;
        }
    }
}
void solve()
{
    bfs();
    int ans=1e18;
    for(int i=1;i<=n;i++)
    {
        ans=min(ans,dis[i][1]);
        ans=min(ans,dis[i][m]);
    }
    for(int i=1;i<=m;i++)
    {
        ans=min(ans,dis[1][i]);
        ans=min(ans,dis[n][i]);
    }
    if(ans>=1e17)
    {
        cout << -1;
    }
    else
    cout << ans;
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
