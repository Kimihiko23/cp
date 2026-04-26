#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;

const int N = 1e5 + 23;

int n, m, q, s, t;
struct C { int u, v; };
vector<int> G[N];
vector<C> E;
int d[N], l[N];
bool v[N];
set<pair<int,int>> B;
int p[N];
vector<int> Q;

void f(int x, int fa) {
    v[x] = true;
    d[x] = l[x] = ++t;
    p[x] = fa;

    for(int i : G[x]) {
        int y = (E[i].u == x) ? E[i].v : E[i].u;
        if(y == fa) continue;
        if(v[y]) {
            l[x] = min(l[x], d[y]);
        } else {
            f(y, x);
            l[x] = min(l[x], l[y]);
            if(l[y] > d[x]) B.insert({min(x,y), max(x,y)});
        }
    }
}

int g(int x) {
    if(!v[x]) return 0;
    int c = 0;
    int cur = x;
    while(cur != s) {
        int fa = p[cur];
        if(fa == -1) break;
        if(B.count({min(cur,fa), max(cur,fa)})) c++;
        cur = fa;
    }
    return c;
}

void read() {
    cin >> n >> m;
    E.resize(m);
    for(int i = 0; i < m; i++) {
        int a,b; cin >> a >> b;
        E[i] = {a,b};
        G[a].pb(i);
        G[b].pb(i);
    }
    cin >> q;
    Q.resize(q);
    for(int i = 0; i < q; i++) cin >> Q[i];
}

void solve() {
    s = n;
    t = 0;
    f(s, -1);

    for(int i = 0; i < q; i++) cout << g(Q[i]) << "\n";
}

main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    read();
    solve();
    //cout << "gay";
}
