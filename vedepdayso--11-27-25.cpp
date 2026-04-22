#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6;
set<int> ans;
int n,q;
int a[N];
map<int,int> dd;
void read()
{
    cin >> n >> q;
    for(int i=1;i<=n+1;i++)
    {
        ans.insert(i);
    }
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        dd[a[i]]++;
        ans.erase(a[i]);
      
    }
}

void solve()
{
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        dd[a[x]]--;
        if (dd[a[x]]<=0)
        {
            dd[a[x]]=0;
        }
        if(dd[a[x]]==0)
        {
            ans.insert(a[x]);
        }
        a[x]=y;
        ans.erase(y);
        dd[y]++;
        cout << *ans.begin() << "\n";
    }
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
