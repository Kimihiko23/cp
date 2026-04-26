#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
int n;
void read()
{
    cin >> n;
}
void solve()
{
    int a=n/3;
    int b=5*3/__gcd(3,5);
    int c=n/b;
    int ans=0;
    for(int i=1;i<=a;i++)
    {
        ans+=3*i;
    }
    for(int i=1;i<=c;i++)
    {
        ans-=15*i;
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
