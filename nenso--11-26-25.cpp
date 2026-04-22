#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6;
set<int> s;
map<int,int> mp;
int a[N];
int n;

void read()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
}

void solve()
{
    int dem=1;
    for(auto i: s)
    {
        mp[i]=dem;
        dem++;
    }
    for(int i=1;i<=n;i++)
    {
        cout << mp[a[i]] << " ";
    }
    //cout << "GAY";
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
