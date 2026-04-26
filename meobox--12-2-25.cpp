#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
int n,k;
vector<int> nha,thu;
void read()
{
    cin >> n >> k;
    for(int i=1; i <= n; i++)
    {
        int x;
        cin >> x;
        nha.pb(x);
    }
    for(int i=1; i <= k; i++)
    {
        int x;
        cin >> x;
        thu.pb(x);
    }
}
void solve()
{
    sort(thu.begin(),thu.end());
    sort(nha.begin(),nha.end());
    int ans=0;
    for(int i=0; i < n ;i++)
    {
        int tam;
        auto it=upper_bound(thu.begin(),thu.end(),nha[i]);
        if(it!=thu.begin())
        {
            it--;
            tam=*it;

        }
        else
        {
            tam=1e18;
        }
        
        ans+=min(abs(tam-nha[i]),abs(*lower_bound(thu.begin(),thu.end(),nha[i])-nha[i]));
    }
    cout << ans;
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
