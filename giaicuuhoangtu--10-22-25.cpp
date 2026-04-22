#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6+5;
int n;
int a[N];
int ans=0;
int snt(int x)
{
    int dem=0;
    for(int i=2;i*i<=x;i++)
    {
        while(x%i==0)
        {
            dem++;
            x/=i;
        }
    }
    if(x>1) dem++;
    return dem;
}
void read()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        ans=max(ans,snt(a[i]));
    }
}

void solve()
{
    cout << ans;
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
