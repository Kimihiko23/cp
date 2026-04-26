#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =1e5+23;

main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("FACTORIAL.INP","r",stdin);
    freopen("FACTORIAL.OUT","w",stdout);
    int t;
    cin >> t;
    int n,m;
    while (t--)
    {
        cin >> n >> m;
        int tam=1;
        for(int i=1;i<=n;i++)
        {
            tam=tam*i%m;
        }
        if (tam==0)
        {
            cout << "YES\n";

        }
        else
        {
            cout << "NO\n";
        }
    }
   return 0;
    
}
