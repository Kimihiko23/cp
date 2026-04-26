#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =1e5+23;
int dp[N]={0};
int a[N]={0};
int n;
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        dp[i]=1;
    }
    int tam;
    int end;
    int tam1,tam2;
    for(int i=2;i<=n;i++)
    {
        end=i-10;
        if (end<=0)
        end=1;
        tam=0;
        for(int j=i-1;j>=end;j--)
        {
            tam1=abs(a[i]-a[j]);
            tam2=sqrt(tam1);
            if (tam2*tam2==tam1 && tam1!=0)
            {
                tam=max(dp[j],tam);
            }
        }
        dp[i]+=tam;
    }
    cout << *max_element(dp+1, dp+n+1);


   
    
}
