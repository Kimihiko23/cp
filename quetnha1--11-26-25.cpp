#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
map<int,int> mp;
int tam=0;
int ans=0;
int n;
void read()
{
    cin >> n;
    int l,r;
    for(int i=1;i<=n;i++)
    {
        cin >> l >> r;
        mp[l]++;
        mp[r+1]--;
    }

}
void solve()
{
    for(auto i: mp)
    {
        tam+=i.se;
        ans=max(tam,ans);
    }
    cout <<ans;
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
