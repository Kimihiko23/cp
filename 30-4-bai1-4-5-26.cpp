#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 200005;
int a[MAXN];
int pos[MAXN]; 
bool del[MAXN];

int main() 
{
    // Tối ưu tốc độ nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Dùng set để quản lý các INDEX (vị trí) còn tồn tại
    set<int> remain_indices;
    
    // Hai priority_queue để lấy giá trị lớn nhất và nhỏ nhất hiện tại
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int i = 1; i <= n; ++i) 
    {
        cin >> a[i];
        pos[a[i]] = i;
        remain_indices.insert(i);
        max_heap.push(a[i]);
        min_heap.push(a[i]);
    }

    int groups = 0;
    while (!remain_indices.empty()) 
    {
        // 1. Lấy giá trị lớn nhất và nhỏ nhất "thực sự" còn tồn tại
        while (!max_heap.empty() && del[max_heap.top()]) max_heap.pop();
        while (!min_heap.empty() && del[min_heap.top()]) min_heap.pop();

        if (max_heap.empty() || min_heap.empty()) break;

        int val_max = max_heap.top();
        int val_min = min_heap.top();

        // 2. Xác định phạm vi index [L, R] giữa hai giá trị này
        int p1 = pos[val_max];
        int p2 = pos[val_min];
        int L = min(p1, p2);
        int R = max(p1, p2);

        // 3. Xóa tất cả các index nằm trong đoạn [L, R]
        // Dùng lower_bound để nhảy thẳng đến vị trí L trong set
        auto it = remain_indices.lower_bound(L);
        while (it != remain_indices.end() && *it <= R) 
        {
            int current_idx = *it;
            del[a[current_idx]] = true; // Đánh dấu giá trị tại index này đã bị xóa
            
            // Xóa phần tử hiện tại và di chuyển iterator đến phần tử kế tiếp
            remain_indices.erase(it++);
        }

        groups++;
    }

    cout << groups << endl;

    return 0;
}