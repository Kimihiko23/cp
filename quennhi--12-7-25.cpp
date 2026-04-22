#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6;
int n,k;
pair<int,int> a[N];
void read()
{
    cin >> n >> k;
    for(int i=1;i <= n; i++)
    {
        cin >> a[i].se;
    }
    for(int i=1;i <= n; i++)
    {
        cin >> a[i].fi;
    }
    
}

void solve()
{
    sort(a+1,a+n+1,greater<pair<int,int>>());
    //normal priority queue top is max heap
    int tam=0;
    int mn=1e18;
    int ans=-1e18;
    priority_queue<int, vector<int>, greater<int>> gt;
    for(int i=1;i <= n; i++)
    {
        tam+=a[i].se;
        if(gt.size()==k)
        {
            tam-=gt.top();
            gt.pop();
        }
        gt.push(a[i].se);
        mn=min(mn,a[i].fi);
        if(i>=k)
        {
            ans=max(ans,tam*mn);
        }
    }
    cout << ans;
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
