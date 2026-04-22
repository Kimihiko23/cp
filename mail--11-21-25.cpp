#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=300;
int n;
char a[N][N];
int a1[N][N];
vector<pair<int,int>> nha;
int stx,sty;
bool check(int x,int y)
{
    if(x>=1 && x<=n && y>=1 && y<=n)
    {
        return true;
    }
    return false;
}
bool bfs(int stx1,int sty1,int mn,int mx)
{
    bool dd[n+23][n+23];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dd[i][j]=false;
        }
    }
    if (a1[stx1][sty1]>mx || a1[stx1][sty1]<mn)
    {
        return false;
    }
    for(int i=0;i<nha.size();i++)
    {
        if(a1[nha[i].fi][nha[i].se]<mn || a1[nha[i].fi][nha[i].se]>mx)
        {
            return false;
        }
    }
    queue<pair<int,int>> q;
    q.push({stx1,sty1});
    vector<int> dx={0,0,1,-1,1,-1,1,-1};
    vector<int> dy={1,-1,0,0,1,-1,-1,1};
    dd[stx1][sty1]=true;
    while(!q.empty())
    {
        int x=q.front().fi;
        int y=q.front().se;
        q.pop();
        for(int i=0;i<8;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(check(xx,yy) && !dd[xx][yy] && a1[xx][yy]>=mn && a1[xx][yy]<=mx)
            {
                dd[xx][yy]=true;
                q.push({xx,yy});
            }
        }
    }
    for(int i=0;i<nha.size();i++)
    {
        if(!dd[nha[i].fi][nha[i].se])
        {
            return false;
        }
    }
    return true;


}
set<int> s;
void read()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> a[i][j];
            if(a[i][j]=='B')
            {
                stx=i;
                sty=j;
            }
            if(a[i][j]=='N')
            {
                nha.pb({i,j});
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> a1[i][j];
            s.insert(a1[i][j]);
        }
    }
}

void solve()
{
    vector<int> v(s.begin(),s.end());
    int ans=1e9;
    for(auto i: v)
    {
        int l=i,r=1e6;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(bfs(stx,sty,i,mid))
            {
                ans=min(ans,mid-i);
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
    }
    //bfs(stx,sty,3,5);
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
