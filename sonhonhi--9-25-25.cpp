#include <bits/stdc++.h>
#define int long long
using namespace std;

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<int> a;
    int n=5;
    for(int i=1;i<=n;i++)
    {
        int tam;
        cin >> tam;
        a.push_back(tam);
    }
    sort(a.begin(),a.end());
    cout << a[1];
    
   
}
