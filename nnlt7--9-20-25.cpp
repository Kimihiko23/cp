#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6+5;
int cost[10] = {6,2,5,5,4,5,6,3,7,6};
int dp[N]; // dp[i] = max số chữ số tạo được với i LED
int pre[N]; // lưu lại chữ số để backtrack
int n;

void read() {
    cin >> n;
}

void solve() {
    for (int i=0;i<=n;i++) dp[i] = -1e18;
    dp[0] = 0;

    for (int i=0;i<=n;i++) {
        if (dp[i] < 0) continue;
        for (int d=0; d<=9; d++) {
            int c = cost[d];
            if (i+c <= n) {
                if (dp[i+c] < dp[i] + 1) {
                    dp[i+c] = dp[i] + 1;
                    pre[i+c] = d;
                } else if (dp[i+c] == dp[i]+1 && d > pre[i+c]) {
                    // nếu số chữ số bằng nhau, ưu tiên chữ số to hơn
                    pre[i+c] = d;
                }
            }
        }
    }

    // backtrack để dựng số lớn nhất
    int len = dp[n];
    string ans="";
    int cur = n;
    while (cur > 0) {
        int d = pre[cur];
        ans.push_back(char('0'+d));
        cur -= cost[d];
    }

    // vì ta backtrack từ phải sang trái, cần đảo chuỗi
    reverse(ans.begin(), ans.end());

    cout << ans << "\n";
}

main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    read();
    solve();
}
