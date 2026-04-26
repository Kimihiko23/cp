#include <bits/stdc++.h>
#define int long long
using namespace std;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < m; i++) {
        int s, d;
        cin >> s >> d;
        
        vector<bool> ok(n + 1, false);
        ok[1] = true;
        
        for (int x = 1; x < n; x++) {
            if (!ok[x]) continue;
            for (int j = 1; j <= d && x + j <= n; j++) {
                int y = x + j;
                if (a[y] <= s) ok[y] = true;
            }
        }
        
        cout << (ok[n] ? "1\n" : "0\n");
    }
    
    return 0;
}
