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

const int MOD = 1000020409;
const int N = 1e5 + 23;

void read()
{

}

void solve()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        
        vector<int> a(n);
        bool has_even = false, has_odd = false;
        
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 == 0) has_even = true;
            else has_odd = true;
        }
        
        // check non-decreasing
        bool sorted = true;
        for (int i = 1; i < n; i++)
        {
            if (a[i] < a[i - 1])
            {
                sorted = false;
                break;
            }
        }
        
        if (sorted)
        {
            cout << "YES\n";
            continue;
        }
        
        if (has_even && has_odd)
            cout << "YES\n";
        else
            cout << "NO\n";
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

    read();
    solve();
}