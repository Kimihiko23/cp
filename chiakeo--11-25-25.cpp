#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6;
int n,m;
map<int,int> mp;
int pre[N];

void read()
{
    pre[0]=0;
    cin >> n >> m;
    int ans=0;
    mp[0]=1;
    for(int i=1;i<=n;i++)
    {
        int x;

        cin >> x;
      
        pre[i]=pre[i-1]+x;
        ans+=mp[pre[i]%m];
        mp[pre[i]%m]++;

    }
    cout << ans;
}

void solve()
{
    
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
