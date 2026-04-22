#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e4;
int q,n,m;
int a[N][N];
bool dd[N][N];
int bfs(int stx,int sty)
{
    queue< pair<int ,int >> q;
    q.push({stx,sty});
    dd[stx][sty]=true;
    int res=0;
    while(!q.empty())
    {
        pair<int ,int > u=q.front();
        q.pop();
        res++;
        int x=u.fi;
        int y=u.se;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx>=1 && xx<=n && yy>=1 && yy<=m 
                && a[xx][yy]==1 && 
                dd[xx][yy]==false && a[xx][yy]==1)
            {
                dd[xx][yy]=true;
                q.push({xx,yy});
            }
        }
    }
    return res;
}
void read()
{
    cin >> n >> m;
    string s;
    for(int i=1;i<=n;i++)
    {
        cin >> s;
        for(int j=1;j<=s.size();j++)
        {
            a[i][j]=s[j-1]-'0';
            dd[i][j]=false;
        }
    }
}

void solve()
{
    
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==1 && dd[i][j]==false)
            {
                int res=bfs(i,j);
                ans=max(ans,res);
            }
        }
    }
    cout << ans << "\n";
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> q;
    while(q--)
    {
    read();
    solve();
    }
    
   
}
