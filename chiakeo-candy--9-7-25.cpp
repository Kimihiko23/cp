#include <bits/stdc++.h>
#define int long long
using namespace std;

main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,k,m; 
    cin>>n>>k>>m;

    int pmax=0;
    for(int p=1;;p++)
    {
        int s=1LL*p*(p-1)/2*(k+1)+p;
        if(s>n){pmax=p-1;break;}
    }

    vector<int> dp(n+1,0), pre(n+1,0);
    pre[0]=1;
    int ans=0;

    for(int i=1;i<=pmax;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int w1=(j>=1?pre[j-1]:0);
            int w2=(j>=i?dp[j-i]:0);
            dp[j]=(w1+w2)%m;
        }
        if(i>=2)
        {
            int need=n-(k+1)*i*(i-1)/2;
            if(need>=0 && need<=n)
             ans=(ans+dp[need])%m;
        }
        pre=dp;
    }

    cout<<ans;
}
