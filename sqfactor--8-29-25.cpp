#include <bits/stdc++.h>
#define int long long
using namespace std;

// Hằng số
const int MAXN = 1e6; // Giới hạn tối đa của R cho subtask 2 (bao gồm cả subtask 1)
const int MOD = 1e9+7; // Modulo theo yêu cầu đề bài

// Biến toàn cục
int T; // Số lượng truy vấn
int f[MAXN+5]; // Mảng lưu giá trị f(i)
int pref[MAXN+5]; // Mảng lưu tổng tiền tố (prefix sum) của mảng f

/**
 * @brief Hàm kiểm tra một số có phải là số chính phương hay không.
 * @param x Số cần kiểm tra.
 * @return true nếu x là số chính phương, false nếu ngược lại.
 */
bool isSquare(int x) {
    if (x < 0) return false;
    int r = round(sqrtl(x)); // Lấy căn bậc hai và làm tròn để xử lý sai số
    return r*r == x;
}

/**
 * @brief Tính toán trước các giá trị cần thiết.
 * Cụ thể là mảng f và mảng tổng tiền tố pref.
 */
void precompute() {
    // Bước 1: Dùng sàng để tính số ước của tất cả các số từ 1 đến MAXN
    vector<int> divs(MAXN+5, 0);
    for (int i=1; i<=MAXN; i++) {
        for (int j=i; j<=MAXN; j+=i) {
            divs[j]++;
        }
    }
    
    // Bước 2: Tính giá trị f(i) theo định nghĩa
    // f(i) = divs[i] nếu i là số chính phương, ngược lại f(i) = 0
    for (int i=1; i<=MAXN; i++) {
        if (isSquare(i)) {
            f[i] = divs[i];
        } else {
            f[i] = 0;
        }
    }
    
    // Bước 3: Tính mảng tổng tiền tố pref
    // pref[i] = f[1] + f[2] + ... + f[i]
    pref[0] = 0;
    for (int i=1; i<=MAXN; i++) {
        pref[i] = (pref[i-1] + f[i]) % MOD;
    }
}

/**
 * @brief Hàm đọc input cho số lượng truy vấn T.
 */
void read() {
    cin >> T;
}

/**
 * @brief Hàm giải quyết các truy vấn.
 */
void solve() {
    while (T--) {
        int L, R;
        cin >> L >> R;
        
        // Tính tổng f(L) + ... + f(R) bằng mảng tổng tiền tố
        // Kết quả = pref[R] - pref[L-1]
        // Cộng MOD trước khi chia lấy dư để đảm bảo kết quả không âm
        int ans = (pref[R] - pref[L-1] + MOD) % MOD;
        cout << ans << "\n";
    }
}

int32_t main() {
    // Tăng tốc độ nhập xuất
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    // Uncomment các dòng sau để đọc/ghi file khi nộp bài
    // freopen("SQFACTOR.INP","r",stdin);
    // freopen("SQFACTOR.OUT","w",stdout);
 freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    // Thực hiện các bước của chương trình
    read();
    precompute();
    solve();

    return 0;
}