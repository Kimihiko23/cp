#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =600;
char a[N][N];
int n,k;
int dis[N][N][10]={0};
void bfs()
{
    dis[1][1][k]=0;
    vector<int> x{1,-1,0,0};
    vector<int> y{0, 0,1,-1};
    queue<pair<int,pair<int,int>>> tt;
    tt.push({1,{1,k}});
    while(!tt.empty())
    {
        int ux=tt.front().fi;
        int uy=tt.front().se.fi;
        
        int nhay=tt.front().se.se;
        tt.pop();
        for(int i=0;i<x.size();i++)
        {
            int x1=ux+x[i];
            int y1=uy+y[i];
            if(x1>=1 && y1>=1 && x1<=n && y1<=n)
            {
                if (a[x1][y1]!='*' && dis[x1][y1][nhay]>dis[ux][uy][nhay]+1)
                {
                    dis[x1][y1][nhay]=dis[ux][uy][nhay]+1;
                    tt.push({x1,{y1,nhay}});
                }
                else 
                if (a[x1][y1]=='*')
                {
                    int x2=x1+x[i];
                    int y2=y1+y[i];
                    if(x2>=1 && x2<=n && y2>=1 && y2<=n)
                    {
                        if (a[x2][y2]!='*' && nhay-1>=0 && dis[x2][y2][nhay-1]>dis[ux][uy][nhay]+1)
                        {
                            dis[x2][y2][nhay-1]=dis[ux][uy][nhay]+1;
                            tt.push({x2,{y2,nhay-1}});
                        }
                    }
                }
            }
        }

    }
}
void read()
{
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> a[i][j];
            for(int i1=0;i1<=k;i1++)
            {
                dis[i][j][i1]=1e18;
            }
        }
    }
}
void solve()
{
    bfs();
    int ans=1e18;
    for(int i=0;i<=k;i++)
    {
        ans=min(ans,dis[n][n][i]);
    }
    if (ans<=1e17)
    cout << ans << "\n";
    else
    cout << "-1\n";
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
