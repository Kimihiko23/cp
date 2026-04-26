#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int left = 0, right = n - 1;
    int steps = 0;
    while (left < right) {
        if (h[left] == h[right]) {
            left++;
            right--;
        } else {
            if (h[left] < h[right]) {
                h[left + 1] += h[left];
                left++;
            } else {
                h[right - 1] += h[right];
                right--;
            }
            steps++;
        }
    }
    cout << steps << endl;
}

main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("xepgach.inp","r",stdin);
    freopen("xepgach.out","w",stdout);
    solve();
    return 0;
}