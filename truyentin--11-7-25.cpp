#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

struct Edge {
    int u, v;
    long long w;
};

long long distSq(Point a, Point b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return dx * dx + dy * dy;
}

struct DSU {
    vector<int> p;
    DSU(int n) {
        p.resize(n);
        for (int i = 0; i < n; ++i) p[i] = i;
    }

    int find(int x) {
        return (p[x] == x ? x : p[x] = find(p[x]));
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        p[a] = b;
        return true;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<Point> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y;

    if (n == 1) {
        cout << 0;
        return 0;
    }

    vector<Edge> e;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            e.push_back({i, j, distSq(a[i], a[j])});

    sort(e.begin(), e.end(), [](Edge A, Edge B) {
        return A.w < B.w;
    });

    DSU dsu(n);
    long long ans = 0;
    int cnt = 0;

    for (auto &ed : e) {
        if (dsu.unite(ed.u, ed.v)) {
            ans = ed.w;
            if (++cnt == n - 1) break;
        }
    }

    cout << ans;
    return 0;
}
