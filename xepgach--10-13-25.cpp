#include <bits/stdc++.h>
#define int long long
using namespace std;
main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    freopen("XEPGACH.INP", "r", stdin);
    freopen("XEPGACH.OUT", "w", stdout);
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int l = 0, r = n - 1;
    int steps = 0;
    while (l < r) {
        if (a[l] == a[r]) {
            l++; r--;
        } else if (a[l] < a[r]) {
            a[l + 1] += a[l];
            l++;
            steps++;
        } else {
            a[r - 1] += a[r];
            r--;
            steps++;
        }
    }
    cout << steps;
}
