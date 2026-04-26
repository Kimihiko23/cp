#include <bits/stdc++.h>
#define int long long 
#define pb push_back
using namespace std;

const int N = 1e5 + 23; 

int n, m;
vector<int> adj[N];


vector<int> ids;
vector<int> low;
stack<int> st;
vector<bool> onStack;
int timer = 0;
int sccCount = 0;
vector<int> sccSizes; 

void tarjanDFS(int u) {
    ids[u] = low[u] = ++timer;
    st.push(u);
    onStack[u] = true;

    for (int v : adj[u]) {
        if (ids[v] == 0) {
            tarjanDFS(v);
            low[u] = min(low[u], low[v]);
        } else if (onStack[v]) {
            low[u] = min(low[u], ids[v]);
        }
    }

 
    if (low[u] == ids[u]) {
        sccCount++;
        int currentSize = 0;
        while (true) {
            int v = st.top();
            st.pop();
            onStack[v] = false;
            currentSize++;
            if (u == v) break;
        }
        sccSizes.pb(currentSize);
    }
}

void read() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v; 
        adj[u].pb(v);
    }
}

void solve() {
 
    ids.assign(n + 1, 0);
    low.assign(n + 1, 0);
    onStack.assign(n + 1, false);
    timer = 0;
    sccCount = 0;


    for (int i = 1; i <= n; ++i) {
        if (ids[i] == 0) { 
            tarjanDFS(i);
        }
    }

  
    sort(sccSizes.rbegin(), sccSizes.rend());


    cout << sccCount << "\n";
    for (int i = 0; i < sccSizes.size(); ++i) {
        cout << sccSizes[i] << (i == sccSizes.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    // freopen("STAGES2.INP", "r", stdin); // [cite: 19]
    // freopen("STAGES2.OUT", "w", stdout); // [cite: 22]
    read();
    solve();
}