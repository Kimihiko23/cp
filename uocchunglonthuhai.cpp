#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("UOCCHUNG.INP", "r", stdin);
    freopen("UOCCHUNG.OUT", "w", stdout);

    int64 a, b;
    cin >> a >> b;
    int64 g = gcd(a, b);

    vector<int64> divs;
    for (int64 i = 1; i * i <= g; ++i) {
        if (g % i == 0) {
            divs.push_back(i);
            if (i != g / i) divs.push_back(g / i);
        }
    }

    sort(divs.begin(), divs.end(), greater<int64>());

    if (divs.size() >= 2) cout << divs[1];
    else cout << -1;

    return 0;
}
