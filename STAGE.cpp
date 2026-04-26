#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 1e5 + 23;
int n, m;
vector<int> canh[N];
vector<int> state;

bool dfs(int u) {
    state[u] = 1;
    for (int v : canh[u]) {
        if (state[v] == 1) return true;  
        if (state[v] == 0 && dfs(v)) return true;
    }
    state[u] = 2; 
    return false;
}

void read() 
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        canh[u].pb(v);
    }
}

void solve() 
{
    state.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (state[i] == 0 && dfs(i)) {
            cout << "CHINHXAC\n";
            return;
        }
    }
    cout << "KHONG\n";
}
main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    read();
    solve();
}
