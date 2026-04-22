#include <bits/stdc++.h>
#define int long long
using namespace std;
const int P = 1000000007;

int inv(int a) {
    int r = 1, e = P - 2;
    while (e) {
        if (e & 1) r = r * a % P;
        a = a * a % P;
        e >>= 1;
    }
    return r;
}

main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; 
    cin >> n;
    while (n--) {
        int k; 
        cin >> k;
        if (k % 2 == 0 || k % 5 == 0) {
            cout << -1 << "\n";
            continue;
        }
        int r = 0, v = 0, m = -1;
        for (int i = 1; i <= k * 2; i++) {
            r = (r * 10 + 1) % k;
            v = (v * 10 + 1) % P;
            if (r == 0) {
                m = v * inv(k) % P;
                break;
            }
        }
        cout << m << "\n";
    }
}
