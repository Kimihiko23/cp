#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n+1), prefix(n+1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prefix[i] = prefix[i-1] + a[i];
    }

    int ans = LLONG_MIN;
    int minPrefix = LLONG_MAX;

    for (int i = k; i <= n; i++) {
        // cập nhật minPrefix cho các prefix[j] với j <= i-k
        minPrefix = min(minPrefix, prefix[i-k]);
        ans = max(ans, prefix[i] - minPrefix);
    }

    cout << ans;
}
