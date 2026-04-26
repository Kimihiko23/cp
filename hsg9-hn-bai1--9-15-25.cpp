#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("MAXPRO.inp","r",stdin);
    freopen("MAXPRO.out","w",stdout);

    int a,b,c,m;
    cin >> a >> b >> c >> m;

    __int128 tam1 = (__int128)a * b;
    __int128 tam2 = (__int128)a * c;
    __int128 tam3 = (__int128)b * c;

    __int128 best = max(tam1, max(tam2, tam3));

  
    int ans = (best % m + m) % m;
    cout << ans;

    return 0;
}
