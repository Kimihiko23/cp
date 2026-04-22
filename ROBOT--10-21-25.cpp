#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=100;
bool visited1[N][N];
bool visited2[N][N];
char a[N][N];
int stx1, sty1, stx2, sty2;
int edx, edy;
int n, m;

void bfs(int x,int y)
{
    queue<pair<int,int>> q;
}
void read()
{
    cin >> n >> m;
    swap(n,m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
            if (a[i][j]=='M')
            {
                edx=i;
                edy=j;
            }
            if (a[i][j]=='1')
            {
                stx1=i;
                sty1=j;
            }
            if (a[i][j]=='2')
            {
                stx2=i;
                sty2=j;
            }
        }
}   

void solve()
{

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
