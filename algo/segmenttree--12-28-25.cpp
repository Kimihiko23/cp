#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=1e5;
int n, m;
int st[400005];
const int minn = -1e18;
int a[N];
void build(int l, int r, int id)
{
    if(l == r)
    {
        st[id] = a[l];
        return;
    }
    int mid = (l+r)>>1;
    build(l, mid, (id << 1));
    build(mid+1, r, (id << 1) | 1);
    /*
    int mid = (l+r)/2;
    build(l, mid, (id*2));
    build(mid+1, r, (id*2) | 1);
    
    */
    st[id] = max( st[id*2], st[id*2+1]);

}
void update (int id, int l, int r, int pos, int val) {
    if (l > pos || r < pos) return;
    else if (l == r) {
        st[id] += val;
        return;
    }
    int mid = (l+r)/2;
    update (id*2, l, mid, pos, val);
    update (id*2+1, mid+1, r, pos, val);
    st[id] = max(st[id*2], st[id*2+1]);
}

int get (int id, int l, int r, int u, int v) {
    if (l > v || r < u) return minn;
    else if (l >= u && r <= v) return st[id];
    int mid = (l+r)/2;
    return max(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

main () {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int t;
        cin >> t;
        if (t == 0) {
            int x, y; cin >> x >> y;
            update(1, 1, n, x, y);
        }
        else {
            int x, y; cin >> x >> y;
            cout << get(1, 1, n, x, y) << "\n";
        }
    }
    return 0;
}
