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
    int n;
    int tam;
    int tong=0;
    cin >> n;
    int ans=0;
    for(int i=0; i<n; i++)
    {
        cin >> tam;
        tong+=tam;
        ans=max(ans, tong);
        if(tong<0) tong=0;
    }
    cout << ans;
    
   
}
