#include <bits/stdc++.h>
#define int long long
using namespace std;
map<string, int> mp;

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        int x;
        cin >> x >> s;
        if (x==1)
        {
            int tam;
            cin >> tam;
            mp[s]+=tam;
        }
        if (x==2)
        {
            mp[s]=0;
        }
        if (x==3)
        {
            cout << mp[s] << "\n";
        }
    }   
    
    
   
}
