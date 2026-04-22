#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6;
int x[N],y[N];
int n;
int ans=0;
void read()
{
    cin >> n;
    for(int i=1;i <= n; i++)
    {
        cin >> x[i];
    }
    for(int i=1;i <= n; i++)
    {
        cin >> y[i];
    }
}

void solve()
{
    for(int i=1;i <=n; i++)
    {
        for(int j=i+1;j <= n; j++)
        {
            int dx=x[j]-x[i];
            int dy=y[j]-y[i];
            ans=max(ans,dx*dx+dy*dy);
        }
    }
    cout << ans;
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.inp", "r", stdin);
    freopen("output.txt", "w", stdout);
    read();
    solve();
    
   
}
