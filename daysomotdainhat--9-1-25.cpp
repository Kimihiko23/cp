#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+23;
int pre[N]={0}, suf[N]={0}, a[N]={0};
int n;
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    int tam=0;
    for (int i=1; i<=n; i++) 
    {
        cin >> a[i];
        if (a[i]==1) 
        {
            tam++;
            pre[i]=tam;
    
        }
        else
        {
            tam=0;
        }
    }
    tam=0;
    for (int i=n; i>=1; i--) 
    {
        
        if (a[i]==1) 
        {
            tam++;
            suf[i]=tam;
    
        }
        else
        {
            tam=0;
        }
    }
    int ans=0;
    for (int i=1; i<=n; i++) 
    {
        ans=max(ans, pre[i-1]+suf[i+1]);
    }
    cout << ans;
    
   
}
