#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, M, a[50];
int L[1<<21], R[1<<21];
int cntL = 0, cntR = 0;

void dqL(int i, int end, int sum){
    if(i > end){
        L[cntL++] = sum;
        return;
    }
    dqL(i+1, end, sum);         
    dqL(i+1, end, sum + a[i]); 
}

void dqR(int i, int end, int sum){
    if(i > end){
        R[cntR++] = sum;
        return;
    }
    dqR(i+1, end, sum);
    dqR(i+1, end, sum + a[i]);
}

main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> M;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int mid = n / 2;
    dqL(1, mid, 0);
    dqR(mid + 1, n, 0);
    sort(R, R + cntR);
    int ans = 0;
    for(int i = 0; i < cntL; i++){
        if(L[i] > M) continue;
        int need = M - L[i];
        ans += upper_bound(R, R + cntR, need) - R;
    }
    cout << ans;
}
