#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=2000;
bool dd[N][N];
int a[N][N];
int n;
int bfs(int stx,int sty,int w)
{
    
    queue<pair<int,int>> tt;
    tt.push({stx,sty});
    int dem=0;
    dd[stx][sty]=true;
    vector<int> x1{-1,0,0,1};
    vector<int> y1{0,1,-1,0};
    while(!tt.empty())
    {
        pair<int,int> u=tt.front();
        tt.pop();
        dem++;
        for(int i=0;i<x1.size();i++)
        {
            if (!dd[u.fi+x1[i]][u.se+y1[i]] && u.fi+x1[i]>=1 && u.fi+x1[i]<=n 
                && u.se+y1[i]>=1 && u.se+y1[i]<=n && (abs(a[u.fi+x1[i]][u.se+y1[i]]-a[u.fi][u.se])<=w))
            {
                tt.push({u.fi+x1[i],u.se+y1[i]});
                dd[u.fi+x1[i]][u.se+y1[i]]=true;
            }
        }
        
        
    }
    return dem;
 
}
bool check(int we)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dd[i][j]=false;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if (!dd[i][j])
            {
                if(bfs(i,j,we)>=((n*n+1)/2))
                {
                    return true;
                }
            }
        }
    }
    return false;
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
}

void solve()
{
    int ans=1e18;
    int l=0,r=1e6;
    int mid=l+r/2;
    while(l<=r)
    {
        mid=(l+r)/2;
        if (check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
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
    //cout << bfs(1,1,9);
    
   
}
