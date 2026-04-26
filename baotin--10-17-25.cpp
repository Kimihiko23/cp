#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N =1e6+23;
int n;
double k;
vector<double> a;
void read()
{
    cin >> k >> n;
    for(int i=1;i<=n;i++)
    {
        int tam;
        cin >> tam;
        a.push_back(tam);
    }
}
void solve()
{
    sort(a.begin(),a.end());
    int vt=0;
    while (lower_bound(a.begin(),a.end(),a[vt]+k)!=a.end())
    {
        auto it=lower_bound(a.begin(),a.end(),a[vt]+k);
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
