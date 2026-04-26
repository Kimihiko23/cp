#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2000;
bool dd[N][N];
char a[N][N]={0};
int n,m;
void bfs(int stx,int sty)
{
    vector<int> x{-1,-1,-1,0 ,0,1 ,1,1};
    vector<int> y{-1, 0, 0,-1,1,-1,0,1};
    queue<pair<int,int>> tt;
    tt.push({stx,sty});
    pair<int,int> u;
    while(!tt.empty())
    {
        u=tt.front();
        tt.pop();
        dd[u.first][u.second]=true;
        for(int i=0;i<8;i++)
        {
            int x1=u.first+x[i];
            int y1=u.second+y[i];
            if (x1>=1 && x1<=m && y1>=1 && y1<=n)
            {
                if(a[x1][y1]=='1' && !dd[x1][y1])
                {
                    dd[x1][y1]=true;
                    tt.push({x1,y1});
                }
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
            cin >> a[i][j];
    }

}
void solve()
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if (a[i][j]=='1' && !dd[i][j])
            {
                ans++;
                bfs(i,j);
            }
        }
    }
    cout << ans;



}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    // freopen("ISLAND.inp","r",stdin);
    //freopen("VSTEPS.out","w",stdout);
    read();
    solve();

}
