#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+23;
int n,a[N];
int dppre[N],dpsuf[N];
int pos;
void read()
{
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
}
void query1(int i)
{
    if (i==0) return;
    int prev=0;   
    for(int j=1;j<i;j++)
        if (a[j]<a[i] && dppre[j]+1==dppre[i])
        {            prev=j;
            break;
        }
    query1(prev);
    cout << i << " ";
}
vector<int> v;
void query2(int i)
{
    if (i==0) return;
    int prev=0;
    for(int j=i+1;j<=n;j++)
        if (a[j]<a[i] && dpsuf[j]+1==dpsuf[i])
        {
            prev=j;
            
            
            break;
        }
    if (i!=pos)
    cout << i << " ";
    query2(prev);
    
}
void solve()
{
    for(int i=1;i<=n;i++)
    {
        dppre[i]=1;
        for (int j=1;j<i;j++)
            if (a[j]<a[i]) dppre[i]=max(dppre[i],dppre[j]+1);
    }
    for(int i=n;i>=1;i--)
    {
        dpsuf[i]=1;
        for (int j=i+1;j<=n;j++)
            if (a[j]<a[i]) dpsuf[i]=max(dpsuf[i],dpsuf[j]+1);
    }
    int ans=0;
    
    for (int i=1;i<=n;i++)
    { 
        ans=max(ans,dppre[i]+dpsuf[i]-1);
        if (ans==dppre[i]+dpsuf[i]-1) pos=i;
    }
    cout << ans << "\n";
    query1(pos);
    query2(pos);
    //reverse(v.begin(),v.end());
    //for(int i=0;i<v.size();i++) cout << v[i] << " ";
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
