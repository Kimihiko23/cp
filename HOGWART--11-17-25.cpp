#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6+23;
vector<char> a[N];
int n,m;
void read()
{
    cin >> n >> m;
    if(n==0 && m==0)
        exit(0);
    for(int i=1;i<=n;i++)
    {
        a[i].clear();
    }
    for(int i=1;i<=n;i++)
    {
        a[i].push_back('@');
        for(int j=1;j<=m;j++)
        {
            char tam;
            cin >> tam;
            a[i].pb(tam);
        }
    }
    //a[1][1]='@';
    //a[n][m]='@';
}
bool check(int x1,int y1)
{
    if(x1>=1 && x1<=n && y1>=1 && y1<=m)
    {
        return true;
    }
    return false;
}
void solve()
{
    int dis[n+23][m+23];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dis[i][j]=1e18;
        }
    }
    deque<pair<int,int>> tt;
    for(int i=1;i<=n;i++)
    {
        if(a[i][1]!='@')
        {
             tt.pb({i,1});
                if(a[i][1]=='#')
                dis[i][1]=0;
                else
                dis[i][1]=1;
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(a[n][i]!='@')
        {
            tt.pb({n,i});
            if(a[n][i]=='#')
                dis[n][i]=0;
                else
                dis[n][i]=1;

        }
    }
    vector<int> dx={-1,1,0,0,1,-1,1,-1};
    vector<int> dy={0,0,-1,1,1,-1,-1,1};
    while(!tt.empty())
    {
        auto u=tt.front();
        tt.pop_front();
        for(int i=0;i<dx.size();i++)
        {
            int x=u.fi+dx[i];
            int y=u.se+dy[i];
            if (check(x,y))
            {
                if(a[x][y]!='@')
                {
                    if(a[x][y]=='.' && dis[x][y]>dis[u.fi][u.se]+1)
                    {
                        dis[x][y]=dis[u.fi][u.se]+1;
                        tt.push_back({x,y});
                    }
                    if(a[x][y]=='#' && dis[x][y]>dis[u.fi][u.se])
                    {
                        dis[x][y]=dis[u.fi][u.se];
                        tt.push_front({x,y});
                    }
                    
                }
            }
        }
    }
    {/*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(dis[i][j]!=1e18)
            cout << dis[i][j] << " ";
            else
            cout << -1 << " ";
        }
        cout << "\n";
    }
    cout << "\n";*/}
    int ans=1e18;
    for(int i=1;i<=n;i++)
    {
        ans=min(ans,dis[i][m]);
    }
    for(int i=1;i<=m;i++)
    {
        ans=min(ans,dis[1][i]);
    }

    if(ans==1e18)
        cout << -1 << "\n";
        else
        cout << ans << "\n";
    
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(1)
    {
        read();
        solve();
    }
    
   
}
