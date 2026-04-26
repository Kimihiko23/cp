#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
int a[N];
int n;
bool dd=false;
void dequy(int sum1,int sum2,int i)
{
    if ( i>=n+1)
    {
        if (sum1 == sum2 && sum1!=0 && sum2!=0)
        {
            dd=true;
        }
        return;
    }
    dequy(sum1+a[i],sum2,i+1);
    dequy(sum1,sum2,i+1);
    dequy(sum1,sum2+a[i],i+1);
}
void read()
{
    cin >> n;
    for(int i=1; i <= n; i++)
    {
        cin >> a[i];
    }
}
void solve()
{
    dequy(0,0,1);
    if(dd)
    cout << "YES";
    else
    cout << "NO";
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    read();
    solve();

   
    
}
