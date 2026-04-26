#include <bits/stdc++.h>
using namespace std;

long long dp[105][105], sumv[105], a[105];

int main() {
    int n;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n;
     
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) sumv[i] = sumv[i-1] + a[i];

    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            dp[l][r] = 0;

            for (int k = l; k < r; k++) {
                dp[l][r] = max(
                    dp[l][r],
                    dp[l][k] + dp[k+1][r] + (sumv[r] - sumv[l-1])
                );
            }
        }
    }

    cout << dp[1][n];
}
