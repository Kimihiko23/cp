#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<int> adj[N]; 
vector<int> rev_adj[N]; 
int n, m, k;
int start_points[105];
bool visited[N];
bool reachable[105][N]; 

void bfs(int start, int idx) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    reachable[idx][start] = true;
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                reachable[idx][v] = true;
                q.push(v);
            }
        }
    }
}


void dfs(int u, int idx) {
    visited[u] = true;
    reachable[idx][u] = true;
    
    for(int v : adj[u]) {
        if(!visited[v]) {
            dfs(v, idx);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    freopen("KEHOACH.INP", "r", stdin);
    freopen("KEHOACH.OUT", "w", stdout);
    
    cin >> k >> n >> m;
    

    for(int i = 0; i < k; i++) {
        cin >> start_points[i];
    }
        for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i = 0; i < k; i++) {
        memset(visited, false, sizeof(visited));
        bfs(start_points[i], i);

    }
    

    int count = 0;
    for(int v = 1; v <= n; v++) {
        bool can_meet = true;
        for(int i = 0; i < k; i++) {
            if(!reachable[i][v]) {
                can_meet = false;
                break;
            }
        }
        if(can_meet) {
            count++;
        }
    }
    
    cout << count << "\n";
    
    return 0;
}