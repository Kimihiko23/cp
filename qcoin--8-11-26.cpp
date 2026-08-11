#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back

typedef pair<int,int> pii;

const int MOD = 1e9+7, MAXN = 6e3 + 2;
vector<int> items[MAXN];
pii a[MAXN];
int dp[MAXN], ans[MAXN];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  int n, s; cin >> n >> s;
  vector<pii> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].fi >> a[i].se;
    items[a[i].fi].pb(a[i].se);
  }
 
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = s; j >= a[i].se; --j) {
      dp[j] = (dp[j] + dp[j-a[i].se]) % MOD;
    }
  }
 
  for (int i = 1; i <= 6000; ++i) {
    for (int j = 0; j <= s; ++j) {
      if (i * j > s) break;
      ans[i*j] = (ans[i*j] + dp[j]) % MOD;
    }
 
    for (auto k : items[i]) {
      for (int j = k; j <= s; ++j) {
        dp[j] = (dp[j] - dp[j-k] + MOD) % MOD;
      }
    }
  }
  cout << ans[s] << '\n';
  return 0;
}