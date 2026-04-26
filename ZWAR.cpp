#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =2000;
bool dd[N][N]={0};
int a[N][N];
int n,m;
bool check(int x,int y)
{
    if(x>=1 && x<=n && y>=1 && y<=m)
        return true;
    return false;
}
int dem=0;
void bfs(int stx,int sty)
{
    dem=0;
    queue<pair<int,int>> tt;
    tt.push({stx,sty});
    vector<int> dx{1,-1,0,0 ,1,-1,-1, 1};
    vector<int> dy{0, 0,1,-1,1,-1,1 ,-1};
    dem++;
    dd[stx][sty]=true;
    while(!tt.empty())
    {
        pair<int,int> u=tt.front();
        tt.pop();
        for(int i=0;i<dx.size();i++)
        {
            if(check(u.fi+dx[i],u.se+dx[i]) && a[u.fi+dx[i]][u.se+dy[i]]==1 && 
                dd[u.fi+dx[i]][u.se+dy[i]]==0)
            {
                dem++;
                dd[u.fi+dx[i]][u.se+dy[i]]=1;
                tt.push({u.fi+dx[i],u.se+dy[i]});
            }
        }

    }
}

void read()
{
    cin >> n >> m;
    //swap(n,m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
            dd[i][j]=0;
        }
    }
}
void solve()
{
    int sl=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==1 && !dd[i][j])
            {
                bfs(i,j);
                sl++;
                ans=max(ans,dem);
            }
        }
    }
    cout << sl << " " << ans << "\n";
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
    read();
    solve();
    }
   
    
}
