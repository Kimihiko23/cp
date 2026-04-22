#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+23;
void read()
{

}
void solve()
{
    int n;
    int tam;
    cin >> n;
    int ans=0,mn=1e18;
    cin >> tam;
    
    for(int i=2;i<=n;i++)
    {
        mn=min(mn,tam);
        cin >> tam;
        ans=max(ans,tam-mn);
        
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
    solve();
    
   
}
