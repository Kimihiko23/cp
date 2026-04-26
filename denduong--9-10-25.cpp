#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =1e5+23;
int dd[N]={0};
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int da,db,a,b,k;
    cin >> da >> a >> db >> b >> k;
    if (da==db && a!=b)
    {
        cout << 0;
        exit(0);
    }
    int bcnn=__gcd(da,db);
    bcnn=da*db/bcnn;
    int tam1=a,tam2=b;
    while (tam1<=N)
    {
        dd[tam1]++;
        tam1+=da;
    }
    while (tam2<=N)
    {
        dd[tam2]++;
        tam2+=db;
    }
    int st=-1;
    for(int i=1;i<=N;i++)
    {
        if (dd[i]==2)
        {
            st=i;
            break;
        }
       //cout << dd[i] << "," << i << " ";
    }
    if (st==-1)
    {
        cout << 0;
        exit(0);
    }
    int ans=0;
    ans=k/bcnn+1;
    cout << ans;
   
}
