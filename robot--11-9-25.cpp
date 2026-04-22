#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=200;
int dis[N][N];
int dd[N][N]={0};
int a[N][N]={0};
int n,m;
int edx,edy;
bool check(int x,int y)
{
    if (x>=1 && x<=n && y>=1 && y<=m)
        return true;
    return false;
}
void bfs()
{
    queue<pair<int,pair<int,int>>> tt;
    tt.push({2,{1,1}});
    dis[1][1]=0;
    dd[1][1]=true;
    while(!tt.empty())
    {
        auto u=tt.front();
        tt.pop();
        //0 up
        //1 right
        //2 down
        //3 left
        if (u.fi==0)
        {
            if(check(u.se.fi,u.se.se-1) && dd[u.se.fi][u.se.se-1]==0)
            {
                tt.push({3,{u.se.fi,u.se.se-1}});
                dd[u.se.fi][u.se.se-1]=1;
                dis[u.se.fi][u.se.se-1]=dis[u.se.fi][u.se.se]+1;
            }
            if(check(u.se.fi-1,u.se.se) && dd[u.se.fi-1][u.se.se]==0)
            {
                tt.push({0,{u.se.fi-1,u.se.se}});
                dd[u.se.fi-1][u.se.se]=1;
                dis[u.se.fi-1][u.se.se]=dis[u.se.fi][u.se.se]+1;
            }
        }
        else if (u.se.se==1)
        {
            if(check(u.se.fi-1,u.se.se) &&dd[u.se.fi-1][u.se.se])
            {
                tt.push({0,{u.se.fi-1,u.se.se}});
                dd[u.se.fi-1][u.se.se]=1;
                dis[u.se.fi-1][u.se.se]=dis[u.se.fi][u.se.se]+1;
            }
            if(check(u.se.fi,u.se.se+1) && dd[u.se.fi][u.se.se+1]==0)
            {
                tt.push({1,{u.se.fi,u.se.se-1}});
                dd[u.se.fi][u.se.se+1]=1;
                dis[u.se.fi][u.se.se+1]=dis[u.se.fi][u.se.se]+1;
            }
        }
        else if (u.se.se==2)
        {
            if(check(u.se.fi,u.se.se+1) && dd[u.se.fi][u.se.se+1]==0)
            {
                tt.push({1,{u.se.fi,u.se.se-1}});
                dd[u.se.fi][u.se.se+1]=1;
                dis[u.se.fi][u.se.se+1]=dis[u.se.fi][u.se.se]+1;
            }
            if(check(u.se.fi+1,u.se.se) &&dd[u.se.fi+1][u.se.se])
            {
                tt.push({2,{u.se.fi+1,u.se.se}});
                dd[u.se.fi+1][u.se.se]=1;
                dis[u.se.fi+1][u.se.se]=dis[u.se.fi][u.se.se]+1;
            }

        }
        else if (u.se.se==3)
        {
            if(check(u.se.fi,u.se.se-1) && dd[u.se.fi][u.se.se-1]==0)
            {
                tt.push({3,{u.se.fi,u.se.se-1}});
                dd[u.se.fi][u.se.se-1]=1;
                dis[u.se.fi][u.se.se-1]=dis[u.se.fi][u.se.se]+1;
            }
            if(check(u.se.fi+1,u.se.se) &&dd[u.se.fi+1][u.se.se])
            {
                tt.push({2,{u.se.fi+1,u.se.se}});
                dd[u.se.fi+1][u.se.se]=1;
                dis[u.se.fi+1][u.se.se]=dis[u.se.fi][u.se.se]+1;
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
            dis[i][j]=1e18;
        }
    }
    cin >> edx>>edy;

}

void solve()
{
    bfs();
    cout << dis[edx][edy];
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
