#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve_floor(ll val, ll mask)
{
    ll res = 0;
    bool tight = true;
    for (int i = 60; i >= 0; i--)
    {
        if (tight)
        {
            if ((val >> i) & 1)
            {
                if ((mask >> i) & 1)
                {
                    res |= (1LL << i);
                }
                else
                {
                    tight = false;
                }
            }
        }
        else
        {
            if ((mask >> i) & 1)
            {
                res |= (1LL << i);
            }
        }
    }
    return res;
}

vector<ll> get_candidates(ll val, ll mask)
{
    vector<ll> cands;
    cands.push_back(solve_floor(val, mask));
    if ((val & mask) == val)
    {
        cands.push_back(val);
    }
    for (int i = 0; i <= 60; i++)
    {
        if (((val >> i) & 1) == 0 && ((mask >> i) & 1) == 1)
        {
            if (((val >> (i + 1)) & ~(mask >> (i + 1))) == 0)
            {
                ll q = (val & (~((1LL << (i + 1)) - 1))) | (1LL << i);
                cands.push_back(q);
            }
        }
    }
    return cands;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        
        ll mask1 = ~x;
        vector<ll> q_cands = get_candidates(y, mask1);
        ll best_q = q_cands[0];
        for (ll q : q_cands)
        {
            if (abs(y - q) < abs(y - best_q))
            {
                best_q = q;
            }
        }
        ll cost1 = abs(y - best_q);
        
        ll mask2 = ~y;
        vector<ll> p_cands = get_candidates(x, mask2);
        ll best_p = p_cands[0];
        for (ll p : p_cands)
        {
            if (abs(x - p) < abs(x - best_p))
            {
                best_p = p;
            }
        }
        ll cost2 = abs(x - best_p);
        
        if (cost1 <= cost2)
        {
            cout << x << " " << best_q << "\n";
        }
        else
        {
            cout << best_p << " " << y << "\n";
        }
    }
    return 0;
}