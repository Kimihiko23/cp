#include <bits/stdc++.h>

using namespace std;

#define task "test"
#define ll long long
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define mp make_pair
#define CC cout << '\n'
#define BASE 256
#define LOG 19
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
template<class x,class y> bool minimize(x &a,const y &b){if(a > b){a = b;return true;}return false;}
template<class x,class y> bool maximize(x &a,const y &b){if(a < b){a = b;return true;}return false;}

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

constexpr int MAXN = 1e6 + 1, MN = 1e3 + 6, MOD = 1e9 + 7;
constexpr ll INF = 1e18;

int n,m,k,l,r,q,timer;
int low[MAXN], num[MAXN], d[MAXN], val[MAXN];
char ans[MAXN];
bool cau[MAXN], vist[MAXN], mark[MAXN];
vector<pii> adj[MAXN], g[MAXN];
struct info{
    int u, v;
};
vector<info> edge;
void dfs(int v,int p = 0){
    low[v] = num[v] = ++num[0];

    for(auto u : adj[v]) if(u.se != p){
        if(!num[u.fi]){
            dfs(u.fi, u.se);
            minimize(low[v], low[u.fi]);
            if(low[u.fi] == num[u.fi]){
                cau[u.se] = true;
            }
        }else{
            minimize(low[v], num[u.fi]);
        }
    }
}

void dfs2(int v){
    d[v] = timer;
    for(auto u : adj[v]){
        if(cau[u.se]) continue;
        if(!d[u.fi]) dfs2(u.fi);
    }
}

void dfs3(int v,int p = 0,int id = 0){
    mark[v] = true;
    for(auto u : g[v]) if(u.fi != p){
        dfs3(u.fi, v, u.se);
        val[v] += val[u.fi];
    }

    if(val[v] < 0) ans[id] = (d[edge[id].u] == p && d[edge[id].v] == v) ? 'R' : 'L';
    else if(val[v] > 0) ans[id] = (d[edge[id].u] == v && d[edge[id].v] == p) ? 'R' : 'L';
    else ans[id] = 'B';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }

    cin >> n >> m;

    edge.pb({0,0});
    FOR(i, 1, m){
        int u, v;
        cin >> u >> v;
        adj[u].pb(mp(v,i));
        adj[v].pb(mp(u,i));
        edge.pb({u,v});
    }

    FOR(i, 1, n){
        if(!num[i]) dfs(i);
    }

    FOR(i, 1, n){
        if(!d[i]) ++timer,dfs2(i);
    }

    FOR(i, 1, m){
        if(!cau[i]) continue;
        int u = d[edge[i].u], v = d[edge[i].v];
        g[u].pb(mp(v,i));
        g[v].pb(mp(u,i));
    }

    int p;
    cin >> p;
    while(p--){
        int u, v;
        cin >> u >> v;
        val[d[u]]++, val[d[v]]--;
    }

    FOR(i, 1, timer){
        if(!mark[i]) dfs3(i);
    }

    FOR(i, 1, m){
        cout << (!ans[i] ? 'B' : ans[i]) ;
    }
    cerr << '\n';
    cerr << "Time elapsed: " << TIME << " s.\n ";
    return (0 ^ 0);
}