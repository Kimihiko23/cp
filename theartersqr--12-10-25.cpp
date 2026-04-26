#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
int n,m,a;
void read()
{
    cin >> n >> m >> a;
    
}
void solve()
{
    //int ans=0;
    int tam1=n/a,tam2=m/a;
    if(n%a!=0)
        tam1=n/a+1;
    if(m%a!=0)
        tam2=m/a+1;
    cout << tam1*tam2;
    
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
