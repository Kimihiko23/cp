#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N =1000;
int n;
int a[N][N]={0};
bool bfs(int wst,int wed)
{
    if (a[1][1]<wst || a[1][1]>wed)
        return false;
    queue < pair < int , int > > q;
    bool visited[N][N]={0};
    vector<int> dirx={-1,1,0,0};
    vector<int> diry={0,0,-1,1};
    q.push({1,1});
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x==n && y==n)
            return true;
        for(int i=0;i<4;i++)
        {
            int newx=x+dirx[i];
            int newy=y+diry[i];
            if(newx>=1 && newx<=n && newy>=1 && newy<=n && 
                !visited[newx][newy] && a[newx][newy]<=wed && a[newx][newy]>=wst)
            {
                visited[newx][newy]=1;
                q.push({newx,newy});
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
    for(int i=0;i<=101;i++)
    {
        for(int j=0;j<=101;j++)
        {
            if(bfs(i,j))
            {
                ans=min(ans,abs(i-j));
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
    read();
    solve();
   
    
}
