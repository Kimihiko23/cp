#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6;
map<int,map<int,int>> mp;
set<int> s;
int n,q;
void read()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        s.insert(x);
        for(int j: s)
        {
            mp[i][j] = mp[i-1][j];
        }
        mp[i][x]++;
    }
    
}

void solve()
{
    cin >> q;
    while(q--)
    {
        int l,r,k;
        cin >> l >> r >> k;
        cout << mp[r][k]-mp[l-1][k] << "\n";
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
