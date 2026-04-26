#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N =1e6 + 10;
array<int, N> a, lis, weight;

main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    lis.fill(LLONG_MAX);
    lis[0] = LLONG_MIN;
    weight.fill(LLONG_MAX);
    weight[0] = 0;

    int n;
    long long w;
    cin >> n >> w;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        int pos = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
        if (a[i] > lis[pos - 1] && a[i] < lis[pos]) {
            lis[pos] = a[i];
            weight[pos] = weight[pos - 1] + a[i];
        }
        else if (a[i] == lis[pos]) {
            weight[pos] = min(weight[pos], weight[pos - 1] + a[i]);
        }
    }

    for (int i = n; i >= 1; --i) {
        if (weight[i] <= w) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << 0 << '\n';

    // for (int i = 1; i <= n; ++i) {
    //     cout << weight[i] << ' ';
    // }


}