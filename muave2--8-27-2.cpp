#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =1e6+23;
int dp[N]={0};
int a[N]={0};
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,one,week,month;
    int tam;
    cin >> n >> one >> week >> month;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        //dp[i]+=dp[i-1];
        //cout << dp[i] << " ";
    }
    int tam1,tam2,tam3;
    for(int i=1;i<=n;i++)
    {
        if (a[i]==1)
        {
        tam1=i-7;
        tam2=i-30;
        if(tam1 <0)
        {
            tam1=0;
        }
        if(tam2<0)
        {
            tam2=0;
        }
        
        dp[i]=min(dp[tam1]+week,min(dp[tam2]+month,dp[i-1]+one));
        }
        dp[i]+=dp[i-1];

    }
    cout << dp[n];
   
    
}
