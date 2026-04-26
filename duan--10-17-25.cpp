#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 23;
int n;
int a[N], b[N];
vector<pair<int,int>> a1; 
vector<pair<int,int>> a2; 

void read()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
}

void solve()
{
    a1.clear();
    a2.clear();

 
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < b[i]) a1.push_back({a[i], b[i]});
        else a2.push_back({a[i], b[i]});
    }

    sort(a1.begin(), a1.end(), [](auto &x, auto &y){
        return x.first < y.first;
    });


    sort(a2.begin(), a2.end(), [](auto &x, auto &y){
        return x.second > y.second;
    });

    long long tam = 0; 
    long long ans = 0; 

    for (auto [a_, b_] : a1)
    {
        tam -= a_;
        if (tam < 0)
        {
            ans += -tam;
            tam = 0;
        }
        tam += b_;
    }

    for (auto [a_, b_] : a2)
    {
        tam -= a_;
        if (tam < 0)
        {
            ans += -tam;
            tam = 0;
        }
        tam += b_;
    }

    cout << ans;
}

main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    read();
    solve();
}
