#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
priority_queue<pair<int,int>> hd;
int n;
void read()
{
    int n;
    cin >> n;

    
}

void solve()
{
    for(int i=1;i<=n;i++)
    {
        int kieu,l,r;
        cin >> kieu >> l >> r;
        if(kieu==1)
        {
            hd.push({l,r});
        }
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
