#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<int> price(m);
    for (int i = 0; i < m; i++) cin >> price[i];

    cin.ignore();

    vector<int> likeMask(m, 0);

    
    for (int person = 0; person < n; person++) {
        string s;
        getline(cin, s);

        stringstream ss(s);
        int x;

        while (ss >> x) {
            --x;
            likeMask[x] |= (1 << person);
        }
    }

    vector<int> pow3(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        pow3[i] = pow3[i - 1] * 3;
    }

    int STATES = pow3[n];

    vector<ll> dp(STATES, INF);
    dp[0] = 0;

    for (int dish = 0; dish < m; dish++) {

        vector<ll> ndp = dp;

        int mask = likeMask[dish];

        for (int state = 0; state < STATES; state++) {

            if (dp[state] == INF) continue;

            int nxt = state;
            bool ok = true;

            for (int p = 0; p < n; p++) {

                if ((mask >> p) & 1) {

                    int cnt = (nxt / pow3[p]) % 3;

                    if (cnt == 2) {
                        ok = false;
                        break;
                    }

                    nxt += pow3[p];
                }
            }

            if (ok) {
                ndp[nxt] = min(ndp[nxt], dp[state] + price[dish]);
            }
        }

        dp = ndp;
    }

    int target = 0;
    for (int i = 0; i < n; i++) {
        target += 2 * pow3[i];
    }

    if (dp[target] == INF) cout << -1;
    else cout << dp[target];
}