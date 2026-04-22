#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6;

int l,r,a,b;
void read()
{
    cin >> l >> r >> a >> b;
}

void solve()
{
    int ans=0;
    ans+=r/a-(l-1)/a;
    ans+=r/b-(l-1)/b;
    int c=a*b/__gcd(a,b);
    ans-=r/c-(l-1)/c;
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
