#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =400;
const int mod=4;
int n,m,q;
char a[N][N];
bool check(int x1,int y1)
{
    return (x1>=1 && x1<=n && y1>=1 && y1<=m);
}
int dist[N][N];
void dial(int stx,int sty)
{
    vector<pair<int,int>> q[4];
    for(int i=0;i<=3;i++)
    {
        q[i].clear();
    }
    //queue<pair<int,int>> dq;
    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,-1,0,1};
    //int dist[N][N];
    
    //dist[stx][sty]=0;
    q[0].pb({stx,sty});
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dist[i][j]=1e9;
        }   
    }
    dist[stx][sty]=0;
    for(int w=0;w<=3*(n + m);w++)
    {
        int k;
        while(!q[w % mod].empty())
        {
            int ux=q[w % mod].back().fi;
            int uy=q[w % mod].back().se;
            //tie(ux, uy) = q[w].back();
            if(a[ux][uy]=='N') k=0;
            else
            if(a[ux][uy]=='W') k=1;
            else
            if(a[ux][uy]=='S') k=2;
            else
            if(a[ux][uy]=='E') k=3;

            /*switch (a[ux][uy]) {
                case 'N': k = 0; break;
                case 'W': k = 1; break;
                case 'S': k = 2; break;
                case 'E': k = 3; break;
            }*/

            q[w % mod].pop_back();
            if(w>dist[ux][uy])
                continue;
            for(int i=0;i<dx.size();i++)
            {
                int x=ux+dx[i];
                int y=uy+dy[i];
                if(check(x,y))
                {
                    int new_k=i;
                    if(abs(k-new_k)==0)
                    {
                        if(dist[x][y]>dist[ux][uy]+1)
                        {
                            dist[x][y]=dist[ux][uy]+1;
                            q[dist[x][y] % mod].pb({x,y});
                        }
                    }
                    else
                    if(abs(k-new_k)==2)
                    {
                        if(dist[x][y]>dist[ux][uy]+3)
                        {
                            dist[x][y]=dist[ux][uy]+3;
                            q[dist[x][y] % mod].pb({x,y});
                        }
                    }
                    else
                    {
                        if(dist[x][y]>dist[ux][uy]+2)
                        {
                            dist[x][y]=dist[ux][uy]+2;
                            q[dist[x][y] % mod].pb({x,y});
                        }
                    }
                }
            }
        }
    }
}
void read()
{
    cin >> n >> m >> q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
        }
    }

}
void solve()
{
    while(q--)
    {
        int stx,sty,edx,edy;
        cin >> stx >> sty >> edx >> edy;
        dial(stx,sty);
        cout << dist[edx][edy] << "\n";
    }
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
