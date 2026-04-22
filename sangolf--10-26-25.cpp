#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=600;
vector<pair<int,int>> ho;
int a[N][N]={0};
int n,m;
bool check(int x,int y,int w)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    bool visited[N][N]={0};
    visited[x][y]=1;
    while(!q.empty())
    {
        auto [i,j]=q.front();
        q.pop();
        vector<pair<int,int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
        for(auto [dx,dy]:directions)
        {
            int ni=i+dx;
            int nj=j+dy;
            if(ni>=1 && ni<=n && nj>=1 && nj<=m && !visited[ni][nj] && abs(a[ni][nj]-a[i][j])<=w)
            {
                visited[ni][nj]=1;
                q.push({ni,nj});
            }
        }
    }
    for(auto [hx,hy]:ho)
        if(!visited[hx][hy])
            return false;
    return true;
}
void read()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> a[i][j];
    int tam;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> tam;
            if(tam==1) ho.pb({i,j});
        }
    }
}

void solve()
{
    int l=0,r=1e9,ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if (check(ho[0].fi,ho[0].se,mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    cout << ans;
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
