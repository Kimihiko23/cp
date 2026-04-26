#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N =1e6+23;
int n,k;
int a[N]={0};
int ans[N]={0};
vector<int> vt;
void read()
{
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        a[i]=1e18;
        ans[i]=1e18;
    }
    for(int i=1;i<=k;i++)
    {
        int tam;
        cin >> tam;
        vt.push_back(tam);
    }
    for(int i=0;i<k;i++)
    {
        int tam;
        cin >> tam;
        a[vt[i]]=tam;
    }
}
void solve()
{
    int tam1=1e18;
    for(int i=1;i<=n;i++)
    {
        tam1=min(tam1,a[i]);
        ans[i]=min(tam1,ans[i]);
        tam1++;
    }
    tam1=1e18;
    for(int i=n;i>=1;i--)
    {
        tam1=min(tam1,a[i]);
        ans[i]=min(tam1,ans[i]);
        tam1++;

        
    }
    for(int i=1;i<=n;i++)
    {
        cout << ans[i] << " ";
    }
    
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
