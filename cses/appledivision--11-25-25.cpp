#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6;
int n;
int ans=1e18;
int v[21];
void dequy(int i,int sum1, int sum2)
{
    if(i>n)
    {
        ans=min(ans,abs(sum1-sum2));
        return;
    }
    dequy(i+1, sum1+v[i], sum2);
    dequy(i+1, sum1, sum2+v[i]);
}
void read()
{
    cin >> n;
    for(int i=1;i<=n; i++)
    {
        cin >> v[i];
    }
    
}

void solve()
{
    dequy(1,0,0);
    cout << ans;
    //cout << "gAY";
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    read();
    solve();
    
   
}
