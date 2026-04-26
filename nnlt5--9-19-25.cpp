#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =1e5+23;
double a,b;

void read()
{
    cin >> a >> b;
}
void solve()
{
    cout << fixed << setprecision(6) << (a*a+b*b)/2 << "\n";
     cout << fixed << setprecision(6) << (abs(a+b))/2 << "\n";
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
