#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
map<int,int> mp;
int n;
int ans=-1e18, dem= 0;
void read()
{
    cin >> n;
    for(int i=1; i <= n; i++)
    {
        int l,r;
        cin >> l >> r;
        mp[l]++;
        mp[r+1]--;
    }
}
void solve()
{
    int tam=0;
    int pre=0;
    for(auto i: mp)
    {
        if(tam == ans)
        {
            dem+=i.fi-pre;
        }
        tam+=i.se;
        if(tam > ans)
        {
            ans=tam;
            dem=0;
            
        }
        
        pre=i.fi;
    }
    cout << ans << "\n" << dem;
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
