#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6;

int n, k;
struct Program {
    int start, end;
};
vector<Program> a;
int dp[100005];

void read()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a.pb({x, y});
    }
}

void solve()
{

    sort(all(a), [](Program &p1, Program &p2) {
        return p1.end < p2.end;
    });
    

    multiset<int> machines; 
    for(int i = 0; i < k; i++) machines.insert(0);
    
    int result = 0;
    
    for(int i = 0; i < n; i++)
    {

        auto it = machines.upper_bound(a[i].start);
        if(it != machines.begin())
        {
            --it;
            int cnt = *it;
            machines.erase(it);
            machines.insert(a[i].end);
            result = max(result, cnt + 1);
        }
    }
    
    cout << result;
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // freopen("DAUTHU.INP", "r", stdin);
    // freopen("DAUTHU.OUT", "w", stdout);
    read();
    solve();
}