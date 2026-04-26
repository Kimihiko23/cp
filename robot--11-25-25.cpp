#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = (long long)1e18;

int n,m,k;
vector<pair<int,int>> g[1005];

vector<int> X, P;
int dist1[1005], distN[1005], distX[5][1005];

void dijkstra(int src, int dist[]) {
    for (int i=1;i<=n;i++) dist[i]=INF;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty()) {
        auto [d,u]=pq.top(); pq.pop();
        if (d!=dist[u]) continue;
        for (auto &e:g[u]) {
            int v=e.first, w=e.second;
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
}

main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n >> m >> k;
    for (int i=0;i<m;i++){
        int a,b,t;
        cin>>a>>b>>t;
        g[a].push_back({b,t});
        g[b].push_back({a,t});
    }
    X.resize(k);
    P.resize(k);
    for (int i=0;i<k;i++) cin>>X[i]>>P[i];

    dijkstra(1, dist1);
    dijkstra(n, distN);
    for (int i=0;i<k;i++) dijkstra(X[i], distX[i]);

    vector<int> perm(k);
    iota(perm.begin(), perm.end(), 0);

    long long ans = INF;

    do {
        long long cur = 0;
        int prev = -1;

        cur += dist1[X[perm[0]]] + P[perm[0]];
        prev = perm[0];

        for (int i=1;i<k;i++){
            cur += distX[prev][X[perm[i]]] + P[perm[i]];
            prev = perm[i];
        }

        cur += distX[prev][n];
        ans = min(ans, cur);

    } while(next_permutation(perm.begin(), perm.end()));

    cout << ans;
}
