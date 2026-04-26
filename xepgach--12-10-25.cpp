#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e6+23;
int n;
int a[N];
void read()
{
    cin >> n;
    for(int i=1;i <= n; i++)
    {
        cin >> a[i];
    }
}
void solve()
{
    int l=1,r=n;
    int cnt=0;
    while(l<=r)
    {
        if(a[l]==a[r])
        {
            l++;
            r--;
        }
        else
        if(a[l]>a[r])
        {
            a[r-1]+=a[r];
            r--;
            cnt++;
        }
        else
        if(a[l]<a[r])
        {
            a[l+1]+=a[l];
            l++;
            cnt++;
        }
        
    }
    cout << cnt;
    
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
