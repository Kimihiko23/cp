#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6;
int x1,x2,x3,x4,x5,x6,x7,x8;
void read()
{
    cin >> x1 >> x2 >> x3 >> x4 >> x5 >> x6 >> x7 ;
}

void solve()
{
    int ans=x1+x2+x3-x4-x5-x6+x7;
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
