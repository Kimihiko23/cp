#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
const int N=1e5+23;
int n;
int f[N];
void fibo()
{
    f[0]=0;
    f[1]=1;
    for(int i=2;i<n+1;i++)
    {
        f[i]=(f[i-1]%mod+f[i-2]%mod)%mod;
    }
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin>>n;
    fibo();
    cout<<f[n];
    
   
}
