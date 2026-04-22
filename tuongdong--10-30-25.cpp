#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6;
int n;

void read()
{
    
}

void solve()
{
    while(cin >> n && n!=0)
    {
        map<vector<int>,int> a;
        for(int i=1;i<=n;i++)
        {
            string s;
            vector<int> key;
            for(int i=1;i<=5;i++)
            {
                int tam;
                cin >> tam;
                key.pb(tam);
            }
            sort(all(key));
            a[key]++;
        }
        int ans=0;
        for(auto v: a)
        {
            ans=max(ans,v.se);
        }
        if (ans==1)
        {
            cout << n << "\n";
        }
        else
        cout << ans << "\n";

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
