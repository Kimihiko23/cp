#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e6+23;
int n,p,q;
int a[N];
int pre[N];
int up[N];
void read()
{
    pre[0]=0;
    up[0]=0;
    a[0]=0;
    cin >> n >> q >> p;
    /*for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }*/
    for(int i=1;i<=q;i++)
    {
        int l,r,w;
        cin >> l >> r >> w;
        up[l]+=w;
        up[r+1]-=w;
    }

}
void solve()
{
    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1]+up[i];
    }
    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1]+pre[i];
    }

    while(p--)
    {
        int l,r;
        cin >> l >> r;
        cout << pre[r]-pre[l-1] << "\n";
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
