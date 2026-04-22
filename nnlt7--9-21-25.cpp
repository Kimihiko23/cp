#include <bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c;
void read()
{
    cin >> a >> b >> c;
}
void solve()
{
    cout << a*3+b*2+c*5;
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
