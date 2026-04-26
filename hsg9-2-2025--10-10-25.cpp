#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =1e5+23;
int pre[N]={0};
int suf[N]={0};
int a[N]={0};
int n;
void read()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
}
void solve()
{
    pre[1]=a[1];
    suf[n]=a[n];
    for(int i=2;i<=n;i++)
        pre[i]=__gcd(pre[i-1],a[i]);
    for(int i=n-1;i>=1;i--)
        suf[i]=__gcd(suf[i+1],a[i]);
    int ans=max(pre[n-1],suf[2]);
    for(int i=2;i<=n-1;i++)
    {
        ans=max(ans,__gcd(pre[i-1],suf[i+1]));
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
