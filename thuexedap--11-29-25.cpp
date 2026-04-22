#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6;
int n,m;
int w[N];
multiset<int> s;
int ans=0;
void read()
{
    cin >> n >> m;
    for(int i=1;i<=n; i++)
    {
        cin >> w[i];
    }
}

void solve()
{
    sort(w+1, w+n+1, greater<int>());
    ans+=1;
    s.insert(w[1]);
    for(int i=2;i<=n ;i++)
    {
        auto it= s.upper_bound(m - w[i]);
        if(it!=s.begin())
        {
            it--;
            s.erase(it);
        }
        else
        {
            ans+=1;
            s.insert(w[i]);
        }
    }
    cout << ans;
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
