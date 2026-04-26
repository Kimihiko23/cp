#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N =100+23;
int n;
bool dd[N][N];
int a[N][N];
vector<pair<int,int>> stdong;
vector<pair<int,int>> stcot;
void bfs(int x,int y,int kieu)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    dd[x][y]=1;
    int x1[7]={-1,-1,-1,0,0,1,1};
    int y1[7]={-1,0,1,-1,1,-1,0};
    while(!q.empty())
    {
        auto t=q.front();
        q.pop();
        int i=t.first;
        int j=t.second;
        for(int k=0;k<7;k++)
        {
            int u=i+x1[k];
            int v=j+y1[k];
            if (u>=1 && u<=n && v>=1 && v<=n && a[u][v]==kieu && dd[u][v]==0)
            {
                dd[u][v]=1;
                q.push({u,v});
            }
        }
    }
}
void read()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i=1;i<n;i++)
    {
        if (a[1][i]==1)
        {
            stdong.pb({1,i});
     
        }
        if (a[i][1]==2)
        {
            stcot.pb({i,1});
       
        }
    }
}
void solve()
{
    for(int i=0;i<stdong.size();i++)
    {
        int x=stdong[i].first;
        int y=stdong[i].second;
        if (dd[x][y]==0)
        {
            bfs(x,y,1);
        }
    }
    for(int i=0;i<stcot.size();i++)
    {
        int x=stcot[i].first;
        int y=stcot[i].second;
        if (dd[x][y]==0)
        {
            bfs(x,y,2);
        }
    }
    int dd1=false,dd2=false;
    for(int i=1;i<=n;i++)
    {
        if (dd[n][i]==1 && a[n][i]==1) dd1=true;
        if (dd[i][n]==1 && a[i][n]==2) dd2=true;
    }
    if (dd1) cout << 1 << "\n";
    else 
    if (dd2) cout << 2 << "\n";
    else 
    if (dd1 && dd2) cout << 3 << "\n";
    else cout << 0 << "\n";
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
