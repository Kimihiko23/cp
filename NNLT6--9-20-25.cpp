#include <bits/stdc++.h>
#define int long long
using namespace std;
int a,b;
void read()
{
    cin >> a >> b;
}
void solve()
{
    cout << a << " + " << b << " = " << a+b << "\n";
    cout << a << " - " << b << " = " << a-b << "\n";
    cout << a << " * " << b << " = " << a*b << "\n";
    cout << a << " div " << b << " = " << a/b;
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
