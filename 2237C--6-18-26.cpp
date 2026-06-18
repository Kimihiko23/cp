#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm kiểm tra xem giá trị X có thể là giá trị lớn nhất của đống vịt ở cuối hay không
bool check(long long X, const vector<long long>& a, int n) {
    long long capacity = 0; // Sức chứa dư thừa tích lũy từ phải sang trái
    
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] <= X) {
            // Đống này nhỏ hơn X, nó tạo ra thêm một lượng sức chứa là (X - a[i])
            // Nhưng tổng sức chứa tại một vị trí không được vượt quá giới hạn tối đa X
            capacity = min(X, capacity + (X - a[i]));
        } else {
            // Đống này lớn hơn X, nó bắt buộc phải tiêu thụ bớt sức chứa dư thừa từ phía sau
            long long required = a[i] - X;
            if (capacity < required) {
                return false; // Không đủ sức chứa để gánh lượng vịt dư thừa này
            }
            capacity -= required;
        }
    }
    
    return true; // Tất cả các đống đều được xử lý hợp lệ với giới hạn X
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long max_val = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_val = max(max_val, a[i]);
    }
    
    // Chặn nhị phân tìm X nhỏ nhất
    // Khoảng tìm kiếm: thấp nhất là phần tử lớn nhất hiện tại (vì giá trị chỉ có tăng hoặc giữ nguyên)
    // Cao nhất là tổng tất cả các đống vịt (trường hợp tệ nhất phải dồn lại)
    long long low = max_val;
    long long high = 5000000000000000LL; // 5 * 10^15 (Đề bài: n = 2*10^5, a[i] = 10^9)
    long long ans = high;
    
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, a, n)) {
            ans = mid;        // Ghi nhận đáp án khả thi
            high = mid - 1;   // Thử tìm giá trị X nhỏ hơn nữa
        } else {
            low = mid + 1;    // X quá nhỏ, phải tăng X lên
        }
    }
    
    cout << ans << "\n";
}

int main() {
    // Tối ưu hóa tốc độ nhập xuất dữ liệu
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("input.txt","r")) 
    {
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}