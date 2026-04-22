#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6;

map<int,vector<int>> mp;
int n,q;
void read()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int x; cin >> x;
        mp[x].pb(i);
    }
}

void solve()
{
    cin >> q;
    while(q--)
    {
        int x; cin >> x;
        if(mp[x].size()==0) cout << -1 << "\n";
        else 
        {
            for(auto v:mp[x]) cout << v << " ";
            cout << "\n";
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
    read();
    solve();
    
   
}
