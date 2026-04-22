#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;

struct ing {
    int x, y, sm, pm, sv, pv;
};

vector<ing> a;

void read() {
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y >> a[i].sm >> a[i].pm >> a[i].sv >> a[i].pv;
}

bool ok(int k) {
    long long total = 0;
    for (auto &v : a) {
        long long need = v.x * k - v.y;
        if (need <= 0) continue;

        long long best = LLONG_MAX;

        long long c1 = (need + v.sm - 1) / v.sm * v.pm;
        long long c2 = (need + v.sv - 1) / v.sv * v.pv;
        best = min(c1, c2);

        long long t = need / v.sv;
        for (long long d = -2; d <= 2; d++) {
            long long t2 = t + d;
            if (t2 < 0) continue;
            long long have = t2 * v.sv;
            long long remain = max(0LL, need - have);
            long long small = (remain + v.sm - 1) / v.sm;
            best = min(best, t2 * v.pv + small * v.pm);
        }

        total += best;
        if (total > m) return false;
    }
    return total <= m;
}

void solve() {
    int l = 0, r = 1e9, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (ok(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans;
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    read();
    solve();
}
