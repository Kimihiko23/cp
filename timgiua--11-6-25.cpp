#include <bits/stdc++.h>
#define int long long
using namespace std;

int L, R;

long long sumLR(long long a, long long b) {
    return b * (b + 1) / 2 - (a - 1) * a / 2;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> L >> R;
    if (L > R) swap(L, R);

    long long l = L, r = R, bestM = L;
    long long bestDiff = LLONG_MAX;

    while (l <= r) {
        long long mid = (l + r) / 2;
        long long leftSum = sumLR(L, mid);
        long long rightSum = sumLR(mid + 1, R);
        long long diff = abs(leftSum - rightSum);

        if (diff < bestDiff) {
            bestDiff = diff;
            bestM = mid;
        }

        if (leftSum < rightSum)
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout << bestM;
}
