/*
tantei wa mou shindeiru
*/
#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define ll long long
#define se second
#define siesta main
using namespace std;
#define name "input"

const int MOD1 = 1000020409;
const int MOD = 1e9 + 7;
const int N = 1e5 + 23;
const int LIM = 31623;

int T;
vector<pair<int,int>> q;
vector<int> prime;
bool dd[LIM + 5];

void read()
{
    cin >> T;
    q.resize(T);
    for (int i = 0; i < T; i++)
        cin >> q[i].fi >> q[i].se;
}

void sieve()
{
    memset(dd, true, sizeof(dd));
    dd[0] = dd[1] = false;

    for (int i = 2; i * i <= LIM; i++)
    {
        if (!dd[i]) continue;
        for (int j = i * i; j <= LIM; j += i)
            dd[j] = false;
    }

    for (int i = 2; i <= LIM; i++)
        if (dd[i])
            prime.pb(i);
}

void solve()
{
    sieve();

    for (auto [L, R] : q)
    {
        vector<bool> ok(R - L + 1, true);

        for (int p : prime)
        {
            if (1LL * p * p > R) break;

            int st = max(1LL * p * p,
                            ((L + p - 1) / p) * 1LL * p);

            for (int j = st; j <= R; j += p)
                ok[j - L] = false;
        }

        if (L == 1)
            ok[0] = false;

        int ans = 0;
        for (bool x : ok)
            ans += x;

        cout << ans << '\n';
    }
}

siesta()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (fopen("input.txt","r"))
    {
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }

    // freopen(name ".inp", "r", stdin);
    // freopen(name ".out", "w", stdout);

    read();
    solve();
}