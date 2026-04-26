#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
multiset<int> mp;
int n,k;
vector<int> a;
void read()
{
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        int tam;
        cin >> tam;
        a.pb(tam);
    }
}
void solve()
{
    int ans=0;
    sort(a.begin(),a.end(),greater());
    for(int i=0;i<a.size();i++)
    {
        auto x=mp.lower_bound(a[i]+k);
        if(x!=mp.end())
        {
            mp.erase(x);
            mp.insert(a[i]);
        }
        else
        {
            ans+=a[i];
            mp.insert(a[i]);
        }
    }
    cout << ans;
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
