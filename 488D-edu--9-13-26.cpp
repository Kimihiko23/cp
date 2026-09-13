#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second

const int MAX = 1e6 + 5;

// Khai báo biến toàn cục
int n, s, k;
int a[MAX];
int dp[MAX];    // dp[i]: Số đoạn tối thiểu để chia tiền tố [1..i]
int vis[MAX];   // vis[i]: 1 nếu tiền tố [1..i] chia được hợp lệ, 0 nếu không
int len[MAX];   // len[i]: Độ dài của đoạn cuối cùng kết thúc tại i

/**
 * Hàm kiểm tra và phân hoạch mảng với giới hạn độ dài tối đa là max_len_limit.
 * Trả về: Mảng chứa độ dài từng đoạn (Trả về mảng rỗng nếu không thể phân hoạch).
 */
vector<int> solve(int max_len_limit) {
    int l = 1;
    multiset<int> st; // Dùng multiset lưu đoạn [l..i] để lấy Max và Min trong O(log N)
    vector<int> res;

    // Reset lại mảng đánh dấu và mảng DP
    fill(vis, vis + n + 1, 0);
    fill(dp, dp + n + 1, 0);

    vis[0] = 1; // Tiền tố rỗng ban đầu xem như đã phân hoạch hợp lệ

    for (int i = 1; i <= n; i++) {
        st.insert(a[i]);

        // 1. Thu hẹp l nếu chênh lệch Max - Min vượt quá s
        while (*st.rbegin() - *st.begin() > s) {
            st.erase(st.find(a[l]));
            l++;
        }

        // 2. Thu hẹp l nếu độ dài đoạn lớn hơn giới hạn max_len_limit
        while (i - l + 1 > max_len_limit) {
            st.erase(st.find(a[l]));
            l++;
        }

        // 3. Thu hẹp l để tìm vị trí l-1 đã từng được phân hoạch thành công
        while (!vis[l - 1] && (i - l >= k)) {
            st.erase(st.find(a[l]));
            l++;
        }

        // 4. Nếu vị trí (l-1) hợp lệ VÀ độ dài đoạn >= k thì cập nhật DP
        if (vis[l - 1] && (i - l + 1 >= k)) {
            dp[i] = dp[l - 1] + 1;
            len[i] = i - l + 1;
            vis[i] = 1;
        }
    }

    // Nếu không thể phân hoạch hết n phần tử
    if (!vis[n]) return {};

    // Truy vết ngược từ n về 0 để lấy danh sách độ dài các đoạn
    int cur = n;
    while (cur > 0) {
        res.push_back(len[cur]);
        cur -= len[cur]; // Lùi lại điểm bắt đầu của đoạn hiện tại
    }

    // Đảo ngược lại vì quá trình truy vết đi từ cuối lên đầu
    reverse(res.begin(), res.end());
    return res;
}

signed main() {
    // Tối ưu hóa đọc/ghi dữ liệu
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (fopen("PHANDOAN.inp", "r")) {
        freopen("PHANDOAN.inp", "r", stdin);
        freopen("PHANDOAN.out", "w", stdout);
    }

    cin >> n >> s >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // GIAI ĐOẠN 1: Tìm cách chia có SỐ ĐOẠN ÍT NHẤT (độ dài tối đa mỗi đoạn là n)
    vector<int> initial_sol = solve(n);

    // Không có cách chia nào thỏa mãn
    if (initial_sol.empty()) {
        cout << -1 << "\n";
        return 0;
    }

    int min_segments = initial_sol.size();
    cout << min_segments << "\n"; // In ra số đoạn ít nhất

    // GIAI ĐOẠN 2: Chặt nhị phân tìm ĐỘ DÀI ĐOẠN DÀI NHẤT LÀ NHỎ NHẤT (Minimax)
    int low = 1, high = n;
    vector<int> best_ans = initial_sol;

    while (low <= high) {
        int mid = (low + high) / 2;
        vector<int> cur_sol = solve(mid);

        // Kiểm tra: Chia được VÀ số đoạn không vượt quá min_segments
        if (!cur_sol.empty() && (int)cur_sol.size() <= min_segments) {
            best_ans = cur_sol; // Ghi nhận đáp án tốt hơn
            high = mid - 1;     // Thử tìm giới hạn độ dài nhỏ hơn
        } else {
            low = mid + 1;      // Nâng giới hạn độ dài lên
        }
    }

    // In ra độ dài của từng đoạn trong phương án tối ưu nhất
    for (int x : best_ans) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}