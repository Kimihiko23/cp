#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;

const int N = 1e7 + 23;
bool dd[N] = {0};
vector<int> primes;
vector<string> ans;
int n;

void sieve() {
    dd[0] = dd[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!dd[i]) {
            primes.pb(i);
            for (int j = i * i; j < N; j += i) {
                dd[j] = 1;
            }
        }
    }
}

void read() {
    cin >> n;
}

bool isPrime(int x) {
    if (x < 2) return false;
    if (x < N) return !dd[x];
    
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

void solve() {
    sieve();
    
    for (int i = 0; i < primes.size() - 1; i++) {

        string s1 = to_string(primes[i]);
        string s2 = to_string(primes[i + 1]);
        string merged = s1 + s2;
        

        if (merged.length() > 18) continue;
        
        int num = stoll(merged);
        
        if (isPrime(num)) {
            ans.pb(merged);
            if (ans.size() >= n) break;
        }
    }
    
    cout << ans[n - 1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    read();
    solve();
    return 0;
}