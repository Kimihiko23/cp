#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
vector<int> a;
const int N=1e5+23;
void read()
{
    cin >> n >> q;
    int tam;
    for(int i=1;i<=n;i++)
    {
        cin >> tam;
        a.push_back(tam);
    }
    sort(a.begin(),a.end());
}
void solve()
{
    for(int i=0;i<n;i++)
    {
        cout << a[i] << " ";
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
