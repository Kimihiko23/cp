#include <bits/stdc++.h>
using namespace std;

const int maxN = 100000;
bool prime[maxN+5];
int d[maxN+5];

void sieve() {
    fill(prime, prime+maxN+5, true);
    prime[0] = prime[1] = false;
    for (int i=2; i*i <= maxN; i++) {
        if (prime[i]) {
            for (int j=i*i; j <= maxN; j+=i)
                prime[j] = false;
        }
    }
}

int bfs(int st, int ed) {
    fill(d, d+maxN+5, -1);
    queue<int> q;
    d[st] = 0;
    q.push(st);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == ed) return d[u];

        vector<int> next;
        if (prime[u]) {
            if (2*u   <= maxN) next.push_back(2*u);
            if (2*u+1 <= maxN) next.push_back(2*u+1);
            if (2*u-1 >= 0)    next.push_back(2*u-1);
        } else {
            if (u+1 <= maxN) next.push_back(u+1);
            if (u+2 <= maxN) next.push_back(u+2);
            if (u-1 >= 0)    next.push_back(u-1);
            if (u-2 >= 0)    next.push_back(u-2);
        }

        for (int v : next) {
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    freopen("CUUHOA2.INP", "r", stdin);
    freopen("CUUHOA2.OUT", "w", stdout);

    int n, k;
    cin >> n >> k;

    sieve();
    cout << bfs(n, k);
}
