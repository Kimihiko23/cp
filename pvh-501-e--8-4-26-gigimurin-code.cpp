#include <bits/stdc++.h>
using namespace std;

// #define int long long
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using ld = long double;
using tpl = tuple<int, int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define pb push_back
#define eb emplace_back

template<class X, class Y> bool ckmx (X &x, const Y &y) {return x < y ? x = y, 1 : 0;}
template<class X, class Y> bool ckmn (X &x, const Y &y) {return x > y ? x = y, 1 : 0;}

const int maxn = 1e6 + 5;
// const int MOD = 1e9+19972207;
int MOD;
const int base = 131;
const int INF = 0x3f3f3f3f;
const ll llINF = 1e18;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int fact[1000005], inv[1000005];
int binpow(int a, int b) {
  int res = 1;
  for (a %= MOD; b; a = (1LL * a * a) % MOD, b >>= 1) if (b & 1) res = (1LL * res * a) % MOD;
  return res;
}
vector<pii> factorize[1000005];
int lpf[1000005];

int nck1(int n, int k) {
  return 1LL * (1LL * fact[n] * inv[k] % MOD) * inv[n-k] % MOD;
}
int nck2(int n, int k) {
  if (n < k) return 0;
  int ans = 1;
  vector<int> primes(1000005, 0);
  for (int i = 1; i <= n; ++i) {
    for (auto j : factorize[i]) {
      primes[j.fi] += j.se;
      if (i <= k) primes[j.fi] -= j.se;
      if (i <= n-k) primes[j.fi] -= j.se;
    }
  }
  for (int i = 2; i <= 1000000; ++i) if (primes[i] != 0) ans = (1LL * ans * binpow(i, primes[i])) % MOD;
  return ans;
}
int nck3(int n, int k) {
  if (n < k) return 0;
  int ans = 1;
  for (int i = 1; i <= k; ++i) {
    ans = (1LL * ans * (n - i + 1)) % MOD;
  }
  ans = (1LL * ans * inv[k]) % MOD;
  return ans;
}
int main()
{
  ios::sync_with_stdio(false); cin.tie(0);
  if (fopen("flowers.INP", "r")) {
    freopen("flowers.INP", "r", stdin);
    freopen("flowers.OUT", "w", stdout);
  } 
  auto start = chrono::steady_clock::now();
  int t; cin >> t >> MOD; 

  fact[0] = 1;
  for (int i = 1; i <= 1000001; ++i) fact[i] = (1LL * fact[i-1] * i) % MOD;
  inv[1000001] = binpow(fact[1000001], MOD-2);
  for (int i = 1000000; i >= 0; --i) inv[i] = (1LL * inv[i+1] * (i+1)) % MOD;

  iota(lpf, lpf + 1 + 1000000, 0);
  for (int i = 2; i * i <= 1000000; ++i) {
    if (lpf[i] == i) {
      for (int j = i * i; j <= 1000000; j += i) if (lpf[j] == j) lpf[j] = i; 
    }
  }
  for (int i = 1; i <= 1000000; ++i) {
    int prev = 0, cnt = 0;
    int cur = i;
    while (cur != 1) {
      if (lpf[cur] != prev) {
        if (prev != 0) factorize[i].pb({prev, cnt});
        prev = lpf[cur];
        cnt = 0;
      }
      cnt++;
      cur /= lpf[cur];
    }
    if (prev != 0) factorize[i].pb({prev, cnt});
  }  
  while (t--) {
    int n, m, k; cin >> n >> m >> k;
    if (MOD == 220797) cout << 1LL * (1LL * nck2(n-1, k) * binpow(m-1, k) % MOD) * m % MOD << '\n';
    else if (t <= 50) cout << 1LL * (1LL * nck3(n-1, k) * binpow(m-1, k) % MOD) * m % MOD << '\n'; 
    else cout << 1LL * (1LL * nck1(n-1, k) * binpow(m-1, k) % MOD) * m % MOD << '\n'; 
  }
  auto end = chrono::steady_clock::now();
  cerr << "Time elapsed: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms\n";
  return 0;
}