#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+23;
vector<int> a[N];
int n,m;
void read()
{
    cin >> n >> m;
    while (m--)
    {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}
void solve()
{
    for(int i=1;i<=n;i++)
    {
        cout << a[i].size() << ' ';
        sort(a[i].begin(),a[i].end());
        for(int j:a[i]) cout << j << ' ';
        cout << '\n';
    }
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
