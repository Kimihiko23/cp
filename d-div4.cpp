#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional> 

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> odds;
    vector<long long> evens;

    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        if (a % 2 == 0) {
            evens.push_back(a);
        } else {
            odds.push_back(a);
        }
    }

   
    if (odds.empty()) {
        cout << 0 << "\n";
        return;
    }


    long long sum_evens = 0;
    for (long long val : evens) {
        sum_evens += val;
    }
    
    sort(odds.begin(), odds.end(), greater<long long>());

    
    long long sum_odds_cut = 0;
    for (size_t i = 0; i < odds.size(); ++i) {
        if (i % 2 == 0) 
        {
            sum_odds_cut += odds[i];
        }
    }
    

    cout << sum_evens + sum_odds_cut << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}