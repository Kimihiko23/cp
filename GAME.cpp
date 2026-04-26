#include <bits/stdc++.h>
#define int long long


using namespace std;

main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   
    freopen("GAME.INP", "r", stdin);
    freopen("GAME.OUT", "w", stdout);

    long long n, t, a, b;
    cin >> n >> t >> a >> b;
    vector<long long> k(n);
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
    }
    long long max_appeal = 0;
    long long current_appeal_sum = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; ++i) {
        long long num_games_considered = i + 1;
        long long time_spent_watching = num_games_considered * b;
        long long time_left_for_playing = t - time_spent_watching;
        if (time_left_for_playing < 0) {
            break;
        }
        long long num_can_play = time_left_for_playing / (a - b);
        long long num_to_play = min(num_games_considered, num_can_play);
        pq.push(k[i]);
        current_appeal_sum += k[i];

        while (pq.size() > num_to_play) {
            current_appeal_sum -= pq.top();
            pq.pop();
        }

        max_appeal = max(max_appeal, current_appeal_sum);
    }

    cout << max_appeal << endl;

    return 0;
}
