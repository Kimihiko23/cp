#include <bits/stdc++.h>
#define int long long
using namespace std;
void read()
{

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
    int a[4];
    int ans=0;
    for(int i=1;i<=3;i++)
    {
        cin >> a[i];
        if (a[i]%2==0)
        {
            ans+=a[i]/2;
        }
        else
        {
            ans+=a[i]/2+1;
        }
    } 
    cout << ans;  
}
