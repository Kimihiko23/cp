#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6;
int n,m;
void read()
{
    
    cin >> n >> m;
}
bool check(int x1,int y1)
{
    if (x1>=1 && x1<=n && y1>=1 && y1<=m)
    {
        return true;
    }
    return false;
}

void solve()
{
    int tam;
    int dis1[n+23][m+23];
    int dis2[n+23][m+23];
    int ans1[n+23][m+23];
    int ans2[n+23][m+23];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> tam;
            if(tam==0)
            {
                dis1[i][j]=dis2[i][j]=1;
            }
            else
            if(tam==3)
            {
                dis1[i][j]=dis2[i][j]=0;
            }
            else
            if(tam==2)
            {
                dis1[i][j]=1;
                dis2[i][j]=0;
            }
            if(tam==1)
            {
                dis1[i][j]=0;
                dis2[i][j]=1;
            }
            ans1[i][j]=1e9;
            ans2[i][j]=1e9;
            
        }
    }
    //dis2=tan;
    //dis1=phuoc;
    //1,1 la tan;
    //n,m la phuoc;
    deque<pair<int,int>> tt;
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
    tt.push_back({1,1});

    ans2[1][1]=0;
   
    while(!tt.empty())
    {
        auto u=tt.front();
        tt.pop_front();
        for(int i=0;i<dx.size();i++)
        {
            int x=u.fi+dx[i];
            int y=u.se+dy[i];
            if(check(x,y))
            {
                if(ans2[x][y]>ans2[u.fi][u.se]+dis2[u.fi][u.se])
                {
                    ans2[x][y]=ans2[u.fi][u.se]+dis2[u.fi][u.se];
                    if(dis2[u.fi][u.se]==1)
                    //what make bfs01 is under here
                    tt.push_back({x,y});
                    else
                    tt.push_front({x,y});
                }
            }
        }
    }
    tt.push_back({n,m});
   
    ans1[n][m]=0;
   
    while(!tt.empty())
    {
        auto u=tt.front();
        tt.pop_front();
        for(int i=0;i<dx.size();i++)
        {
            int x=u.fi+dx[i];
            int y=u.se+dy[i];
            if(check(x,y))
            {
                if(ans1[x][y]>ans1[u.fi][u.se]+dis1[u.fi][u.se])
                {
                    ans1[x][y]=ans1[u.fi][u.se]+dis1[u.fi][u.se];
                    if(dis1[u.fi][u.se]==1)
                    //this too
                    tt.push_back({x,y});
                    else
                    tt.push_front({x,y});
                }
            }
        }
    }
    int ans=1e9;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ans=min(ans,ans1[i][j]+ans2[i][j]);
        }
 
    }
    cout << ans << "\n";
    
}

main()
{
    //https://codeforces.com/group/NLfcjc5iua/contest/405649/problem/ZB
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CAFE.inp", "r", stdin);
    freopen("CAFE.out", "w", stdout);
    int q;
    cin >> q;
    while(q--)
    {
        read();
        solve();
    }
    
   
}