#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6+5;
int n;
double k;
double a[N];

bool check(double x) {
    for (int i = 1; i < n; i++) {
        if (a[i+1] - a[i] > 2*x + k)
            return false;
    }
    return true;
}

void read() {
    cin >> k >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    sort(a+1, a+n+1);
}

void solve() {
    double l = 0, r = 1e9, ans = 1e18;
    while (r - l > 1e-4) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << fixed << setprecision(3) << ans;
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
