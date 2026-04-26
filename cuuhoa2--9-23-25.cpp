#include <bits/stdc++.h>
#define int long long
using namespace std; 
const int maxN = 1e5+23;

int d[maxN];
bool visited[maxN];
vector<int> g[maxN];
bool prime[maxN];
int st, ed;

void sieves() {
    fill(prime, prime+maxN, true);
    prime[0] = prime[1] = false;
    for (int i=2; 1LL*i*i<maxN; i++) {
        if (prime[i]) {
            for (int j=i*i;j<maxN;j+=i) {
                prime[j]=false;
            }
        }
    }
}

void bfs(int s,int k) { 
    fill_n(d, ed+1, 0);
    fill_n(visited, ed+1, false);

    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u==k) {
            cout<<d[u];
            return;
        }
        for (auto v : g[u]) {
            if (v<st || v>ed) continue; // bắt buộc trong đoạn
            if (!visited[v]) {
                d[v] = d[u] + 1;
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void read() {
    cin>>st>>ed;
    sieves();
    for (int i=st;i<=ed;i++) g[i].clear();

    for (int i=st;i<=ed;i++) {
        if (prime[i]) {
            if (2*i   <= ed && 2*i   >= st) g[i].push_back(2*i);
            if (2*i+1 <= ed && 2*i+1 >= st) g[i].push_back(2*i+1);
            if (2*i-1 <= ed && 2*i-1 >= st) g[i].push_back(2*i-1);
        } else {
            if (i+1 <= ed && i+1 >= st) g[i].push_back(i+1);
            if (i-1 <= ed && i-1 >= st) g[i].push_back(i-1);
            if (i+2 <= ed && i+2 >= st) g[i].push_back(i+2);
            if (i-2 <= ed && i-2 >= st) g[i].push_back(i-2);
        }
    }
}

void solve() { bfs(st,ed); }

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    read();
    solve();
}
