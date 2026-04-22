#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6;
vector<string> names;
int K, W;
string X;

void read()
{

    string line;
    while (getline(cin, line)) {
        if (!line.empty()) break;
    }
    // tokenize
    {
        stringstream ss(line);
        string t;
        while (ss >> t) names.pb(t);
    }

    if (!(cin >> K >> W)) return;

    cin >> X;
}

void solve()
{
    if (names.empty()) return;
    int n = (int)names.size();
    int totalSessions = K * W;

    for (int week = 0; week < W; ++week) {

        for (int s = 0; s < K; ++s) {
            int idx = (week * K + s) % n;
            cout << names[idx];
        }
        if (week + 1 < W) cout << ' ';
    }
    cout << '\n';

    int cnt = 0;
    for (int i = 0; i < totalSessions; ++i) {
        if (names[i % n] == X) ++cnt;
    }
    cout << cnt << '\n';
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
