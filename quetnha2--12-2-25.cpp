#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6;
int n;
map<int,int> mp;
void read()
{
    cin >> n;
    for(int i =1 ; i<=n ; i++)
    {
        int l,r;
        cin >> l >> r;
        mp[l]++;
        mp[r]--;
    }
}

void solve()
{
    int ans=0;
    int tam=0;
    int vt=0;
    for(auto i: mp)
    {
        tam+=i.se;
        if (tam>ans)
        {
            vt=i.fi;
            ans=tam;
        }
    }
    cout << vt << " " << ans;
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
