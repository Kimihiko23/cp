#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int pre[N]={0} ;
int ans[N]={0};
int n,h;
void read()
{
    cin >> n >> h;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin >> x;
        if (i%2==1)
        {
            pre[1]++;
            pre[x+1]--;
        }
        else
        {
            pre[h-x+1]++;
            pre[h+1]--;
        }
    }
}
void solve()
{
    int mn=1e18;
    for(int i=1; i<=h; i++)
    {
        int tam=0;
        if (i-1>=0) tam=ans[i-1];
        ans[i]=tam+pre[i];
        mn=min(mn, ans[i]);
    }
    int dem=0;
    for(int i=1; i<=h; i++)
    {
        if (ans[i]==mn) dem++;
    }
    cout << mn << " " << dem;
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
