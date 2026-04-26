#include <bits/stdc++.h>
using namespace std;

main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    freopen("input.inp","r", stdin);
    freopen("output.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[1000];
    long long ch=0;
    for (int i=1;i<=k;i++) 
    {
        cin>>a[i];
        ch+=n/a[i];
    }
    long long res = n - ch;
    cout<<res;
}