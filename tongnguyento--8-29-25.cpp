#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =2e6+23;
const int mod=1;
int dp[N]={0};
int a[N]={0};
int n;
bool dd[N];
void sang()
{
    for(int i=1;i<N;i++)
    {
        dd[i]=true;
    }
    dd[1]=false;
    dd[0]=false;
    for(int i=2;i<N;i++)
    {
        if (dd[i]==true)
        {
            for(int j=i*i;j<N;j+=i)
            {
                dd[j]=false;
            }
        }
    }
}
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
    sang();
    int tam;
    int end;
    int tam1,tam2;
    for(int i=1;i<=n;i++)
    {
        tam=0;
        for(int j=1;j<i;j++)
        {
            tam1=(a[i]%mod+a[j]%mod)%mod;
            if (dd[tam1])
            {
                tam=max(dp[j],tam);
            }
        }
        dp[i]+=tam;
    }
    cout << *max_element(dp+1, dp+n+1);


   
    
}
