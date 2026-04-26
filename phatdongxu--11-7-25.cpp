#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e6+23;
int n,m;
map<int,int> manghieu;
int a[N]={0};

void read()
{
    cin >> n >> m;
    for (int i=1;i<=m;i++)
    {
        int l,r;
        cin >> l >> r;
        if (l<=r)
        {
            manghieu[l]++;
            manghieu[r+1]--;
        }
        else
        {
            manghieu[1]++;
            manghieu[r+1]--;
            manghieu[l]++;
            manghieu[n+1]--;
        }
    }
}
void solve()
{
    int tong=0;
    int ans=-1e18;
    for(auto i:manghieu)
    {
        tong += i.se;
        ans=max(ans,tong);
    }
    int pre=1;
    int tam=0;
    int dem=0;
    for(auto i:manghieu)
    {
        if (tam==ans)
        {
            dem+=i.fi-pre;
    
            //cout << pre << " " << i.fi << "\n";
        }
        tam+=i.se;
        pre=i.fi;
    }
    cout << ans << " " << dem;
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
