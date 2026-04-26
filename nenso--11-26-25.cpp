#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
pair<int,int> a[N];
int n;
bool cmp(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    return a.second < b.second; // ascending order
}
void read()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i].first;
        a[i].se=i;
    }
}
void solve()
{
    sort(a+1,a+1+n);
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        cout << a[i].fi;
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
