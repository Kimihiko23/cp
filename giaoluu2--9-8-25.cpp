#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =1e6+23;
int dp[N]={0};
int pre[N]={0};
const int mod=1e9+7;

main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k;
    cin >> n >> k;
    if (k>1)
    {
    dp[0]=1;
    dp[1]=2;
    pre[0]=1;
    pre[1]=3;
    for(int i=1;i<k;i++)
    {
        dp[i]=dp[i-1]*2%mod;
        pre[i]=(pre[i-1]%mod+dp[i])%mod;
        //cout << pre[i] << " ";
    }
    //pre[0]=0;
    for(int i=k;i<=n;i++)
    {
        int tam=i-k;
        int cong;
        if (tam<=0)
        {
            cong=0;
        }
        else
        {
            cong=pre[i-k-1];
        }
        dp[i]=(pre[i-1]%mod-cong%mod+mod)%mod;
        pre[i]=(pre[i-1]%mod+dp[i])%mod;
    }
    cout << dp[n];
    }
    else
    {
    cout << 1;
    } 

   
    
}
