#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6;
int n;
int pre[N]={0};

void read()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        pre[i]=pre[i-1]+x;
    }
}

void solve()
{
    int q;
    cin >> q;
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        cout << pre[r]-pre[l-1] << "\n";
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
