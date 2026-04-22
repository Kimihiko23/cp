#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> x(N), y(N);
    unordered_map<int, int> cntCol, cntRow;

    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i];
        cntCol[x[i]]++;
        cntRow[y[i]]++;
    }

    long long ans = 0;
    for(int i = 0; i < N; i++){
        long long col = cntCol[x[i]] - 1;
        long long row = cntRow[y[i]] - 1;
        ans += col * row;
    }

    cout << ans;
    return 0;
}
