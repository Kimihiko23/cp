#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+23;
int n,x;
void read()
{
  
}
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> x >> n;
        if (n%2==0)
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << x << "\n";
        }
    }
}
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
    
   
}
