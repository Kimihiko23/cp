#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6;
int n;
int tam;
int a[N];
int ans=0,vtans=1,demans=0;
void read()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        a[i+n]=a[i];
    }
}

void solve()
{
    for(int i=1;i <= n; i++)
    {
        tam=0;
        int dem=0;
        int vt=i;
        for(int j=i;j <= i+n-1; j++)
        {
            //cout << j <<" ";
            tam+=a[j];
            dem++;
            if(ans<tam)
            {
                ans=tam;
                demans=dem;
                vtans=vt;
            }
            if(tam<0)
            {
                tam=0;
                vt=j+1;
                dem=0;
            }
        }
    }
    if(vtans>n)
    {
        vtans-=n;
    }
    cout << ans << "\n";
    cout << vtans << " " << demans;
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    read();
    solve();
    
   
}
