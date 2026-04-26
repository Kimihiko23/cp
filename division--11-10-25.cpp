#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
int ans=0;
int n,k;
int a[N]={0};
void read()
{
    cin >> n >> k;
    ans=n;
    for(int i=1;i<=k;i++)
    {
        cin >> a[i];
    }
}
void solve()
{
    for(int i=1;i<=k;i++)
    {
        ans-=n/a[i];
    }
    cout << ans << "\n";
    for(int i=1;i<=k;i++)
    {
        for(int j=i+1;j<=k;j++)
        {
                ans+=n/(a[i]*a[j]/__gcd(a[i],a[j]));
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
