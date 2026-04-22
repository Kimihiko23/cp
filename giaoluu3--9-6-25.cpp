#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int dp[N]={0};
const int mod=1e9+7;
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,k;
    int tam;
    cin >> n >> k;
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        if (i-k-1<=0)
        {
            tam=1;
        }
        else
        {
            tam=dp[i-k-1];
        }
        dp[i]=dp[i-1]+tam;
        dp[i]%=mod;
        //cout << i << " "<< dp[i] << "\n ";
    }
    cout << dp[n];

    
   
}
