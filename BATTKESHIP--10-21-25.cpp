#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N =1e4+23;
int a[N][N]={0};
int ans=0;
int n,m,k;
void loang(int x,int y)
{
    if (x<1 || x>n || y<1 || y>m) return;
    if (a[x][y]==0) return;
    if (a[x][y]==1) ans--;
    a[x][y]=0;
    if (a[x+1][y]==1) loang(x+1,y);
    if (a[x-1][y]==1) loang(x-1,y);
    if (a[x][y+1]==1) loang(x,y+1);
    if (a[x][y-1]==1) loang(x,y-1);
}
void read()
{
    // n la dong , m la cot
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
            if (a[i][j]==1)
            {
                ans++;
            }
        }
    }
}
void solve()
{
    while (k--)
    {
        int x1,y1;
        cin >> x1 >> y1;
        loang(x1,y1);
        cout << ans << "\n";
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
