#include <bits/stdc++.h>
#define int long long
using namespace std;
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
void read()
{

    cin >> n;
}
void solve()
{
    unsigned long long c = n & -n;
    unsigned long long r = n + c;
    unsigned long long m = (((r ^ n) >> 2) / c) | r;

    cout << m;
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
