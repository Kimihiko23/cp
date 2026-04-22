#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6+5;
int n;
double k;
double a[N];
double tam[N];
bool check(double x)
{
    
    tam[0]=0;
    for(int i=1;i<=n;i++)
    {
        tam[i]=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if (tam[i-1]+k>=tam[i])
        {
            tam[i]=min(tam[i]+x,tam[i-1]+k);
            //cout << "debug 1\n";
        }
        else
        {
            if (tam[i]-x>tam[i-1]+k)
            {
                //cout << "debug 0\n";
                return false;
            }
            else
            {
                tam[i]=max(tam[i]-x,tam[i-1]+k);
                //cout << "debug 1\n";
            }
        }
    }
    /*for(int i=1;i<=n;i++)
    {
        cout << fixed << setprecision(3) << tam[i] << "\n";
    }*/
    return true;
}
void read()
{
    cin >> k >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    //cout << k;
    //cout << "gay";

}

void solve()
{
    double l=0,r=1e9;
    double mid=(l+r)/2;
    double ans=1e18;
    while (r - l > 1e-4)
    {
        mid=(l+r)/2;
        if (check(mid))
        {
            ans=min(ans,mid);
            r=mid-0.00001;
        }
        else
        {
            l=mid+0.00001;
        }
    }
    cout << fixed << setprecision(3) << ans << "\n";
  
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
