#include <bits/stdc++.h>
using namespace std;
const string vowels = "aeiou";

int n;
vector<vector<int>> g;
vector<int> val;
vector<int> visited;

pair<int,int> dfs(int u, int p, int sum) {
    pair<int,int> best = {sum, u};
    for (int v : g[u]) {
        if (v == p) continue;
        auto cur = dfs(v, u, sum + val[v]);
        best = max(best, cur);
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;

    val.resize(n+1);
    for (int i=1; i<=n; i++) {
        val[i] = vowels.find(s[i]) != string::npos;
    }

    g.assign(n+1, {});
    for (int i=0; i<n-1; i++) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }


    auto p1 = dfs(1, 0, val[1]);
    auto p2 = dfs(p1.second, 0, val[p1.second]);
    cout << p2.first << "\n";
}
