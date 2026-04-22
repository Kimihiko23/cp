#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

int n, m, D;
vector<int> hasGuard;
vector<vector<int>> adjList;

void readGraph() {
    cin >> n >> m >> D;
    hasGuard.assign(n + 1, 0);
    adjList.assign(n + 1, {});

    // Mark guarded islands
    for (int i = 0; i < D; i++) {
        int x;
        cin >> x;
        hasGuard[x] = 1;
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void solve() {
    vector<int> minGuards(n + 1, INF);   // minimal guards encountered to reach node
    vector<int> minLength(n + 1, INF);   // minimal path length for such guard count
    
    queue<int> q;

    // Initialization
    minGuards[1] = hasGuard[1];
    minLength[1] = 0;
    q.push(1);

    // Modified BFS with lexicographic relaxation
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adjList[u]) {
            int guards = minGuards[u] + hasGuard[v];
            int length = minLength[u] + 1;

            // Relax in lexicographic order:
            // (guards, length) is better than current?
            if (guards < minGuards[v] ||
               (guards == minGuards[v] && length < minLength[v])) 
            {
                minGuards[v] = guards;
                minLength[v] = length;
                q.push(v);
            }
        }
    }

    cout << minGuards[n] << " " << minLength[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    readGraph();
    solve();
    return 0;
}
