#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
int n;
pair<int,int> a[N];
vector<pair<int,int>> nux[N],nuy[N];
void read()
{
    cin >> n;
    int x,y;
    for(int i=1;i<=n;i++)
    {
        cin >> x >> y;
        a[i]={x,y};
        nux[x].pb({x,y});
        nuy[y].pb({x,y});
    }
}
void solve()
{
    cout << nuy[2].size();
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
