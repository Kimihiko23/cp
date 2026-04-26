#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =1e3+23;
int pre[N][N]={0};
int n,r;
void read()
{
    cin >> n >> r;
      for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
            int tam;
            cin >> tam;
            pre[i][j]=tam+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
            
            }
        }
}
bool check(int k)
{
    int tamans=1e18;
    for(int i=1;i<=n-k+1;i++)
    for(int j=1;j<=n-k+1;j++)
    {
        int tam1;
        tam1=pre[i+k-1][j+k-1]-pre[i+k-1][j-1]-pre[i-1][j+k-1]+pre[i-1][j-1];
        tamans=min(tamans,tam1);
    }
    if (tamans<=r)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void solve()
{
    int l,r,mid;
    l=1,r=n;
    int ans=0;
    while (l<=r)
    {
        mid=(r-l)/2+l;
        if (check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
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
