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
// const int MOD = 1e9 + 22071997;
int MOD;
const int base = 131;
const int INF = 2e9;
const ll llINF = 1e18;
int dx[] = {-1, 1, 2, 2};
int dy[] = {2, 2, 1, -1};

int t;
int binpow(int a, int b) {
  int res = 1;
  for (a %= MOD; b; a = (1LL * a * a) % MOD, b >>= 1) if (b & 1) res = (1LL * res * a) % MOD;
  return res;
}

void subtask1() {
  vector<ll> fact(21, 1);
  for (int i = 2; i <= 20; ++i) fact[i] = fact[i-1] * i;
  while (t--) {
    int n, c; cin >> n >> c;  
    cout << (fact[n+c] / fact[c] / fact[n] - 1) % MOD << '\n';
  }
}

void subtask2() {
  vector<vector<int>> nck(10005, vector<int>(5005, 0));
  nck[0][0] = 1;
  for (int i = 1; i <= 10000; ++i) {
    nck[i][0] = 1;
    for (int j = 1; j <= min(i, 5000); ++j) nck[i][j] = (nck[i-1][j] + nck[i-1][j-1]) % MOD;
  }
  while (t--) {
    int n, c; cin >> n >> c;
    cout << (nck[n+c][c] - 1 + MOD) % MOD << '\n';
  }
}

void subtask3() {
  vector<int> fact(2000005, 1), inv(1000005, 1);
  for (int i = 2; i <= 2000000; ++i) fact[i] = (1LL * fact[i-1] * i) % MOD;
  inv[1000000] = binpow(fact[1000000], MOD - 2);
  for (int i = 999999; i >= 0; --i) inv[i] = (1LL * inv[i+1] * (i+1)) % MOD;
  auto nck = [&](int n, int k) -> int {
    return 1LL * (1LL * fact[n] * inv[k] % MOD) * inv[n-k] % MOD;
  };
  while (t--) {
    int n, c; cin >> n >> c;
    cout << (nck(n+c, c) - 1 + MOD) % MOD << '\n';
  }
}

void subtask4() {
  vector<int> fact(1000005, 1), inv(1000005, 1);
  for (int i = 2; i <= 1000000; ++i) fact[i] = (1LL * fact[i-1] * i) % MOD;
  inv[1000000] = binpow(fact[1000000], MOD - 2);
  for (int i = 999999; i >= 0; --i) inv[i] = (1LL * inv[i+1] * (i+1)) % MOD;

  auto nck = [&](ll n, int k) -> int {
    if (n < k) return 0;
    int ans = 1;
    n %= MOD;
    for (int i = 1; i <= k; ++i) {
      ans = (1LL * ans * (n - i + 1 + MOD) % MOD);
    }
    ans = (1LL * ans * inv[k] % MOD);
    return ans;
  };

  while (t--) {
    ll n; int c; cin >> n >> c;
    cout << (nck(n+c, c) - 1 + MOD) % MOD << '\n';
  }
}

void subtask5() {
  vector<bool> isprime(2000005, 1);
  isprime[0] = isprime[1] = 0;
  for (int i = 2; i * i <= 2000000; i++) {
    if (isprime[i]) {
      for (int j = i * i; j <= 2000000; j += i) isprime[j] = 0;
    }
  }
  vector<int> primes;
  for (int i = 2; i <= 2000000; ++i) if (isprime[i]) primes.pb(i);
  auto getexp = [&](int n, int p) -> int {
    int ans = 0;
    for (ll pw = p; pw <= n; pw *= p) ans += n / pw;
    return ans;
};

  auto nck = [&](int n, int k) -> int {
    if (n < k) return 0;
    int ans = 1;
    for (auto i : primes) {
      int exp = getexp(n, i) - getexp(k, i) - getexp(n-k, i);
      if (exp > 0) ans = (1LL * ans * binpow(i, exp)) % MOD;
    }
    return ans;
  };

  while (t--) {
    int n, c; cin >> n >> c;
    cout << (nck(n+c, c) - 1 + MOD) % MOD << '\n';
  }
}

int main()
{
  ios::sync_with_stdio(false); cin.tie(0);
  if (fopen("walls.INP", "r")) {
    freopen("walls.INP", "r", stdin);
    freopen("walls.OUT", "w", stdout);
  } 
  auto start = chrono::steady_clock::now();
  
  int subtask; cin >> subtask >> t >> MOD;  
  
  if (subtask == 1) subtask1();
  if (subtask == 2) subtask2();
  if (subtask == 3) subtask3();
  if (subtask == 4) subtask4();
  if (subtask == 5) subtask5();
  auto end = chrono::steady_clock::now();
  cerr << "Time elapsed: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms\n";
  return 0;
}