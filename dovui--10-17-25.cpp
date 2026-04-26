#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;

int cost(int x)
{
    if (x <= 100) return x * 2;
    if (x <= 10000) return 100 * 2 + (x - 100) * 3;
    if (x <= 1000000) return 100 * 2 + (10000 - 100) * 3 + (x - 10000) * 5;
    return 100 * 2 + (10000 - 100) * 3 + (1000000 - 10000) * 5 + (x - 1000000) * 7;
}

int revCost(int money)
{
    // Tính ngược lại: từ số tiền -> ra số kWh
    if (money <= 100 * 2) return money / 2;
    money -= 100 * 2;
    if (money <= (10000 - 100) * 3) return 100 + money / 3;
    money -= (10000 - 100) * 3;
    if (money <= (1000000 - 10000) * 5) return 10000 + money / 5;
    money -= (1000000 - 10000) * 5;
    return 1000000 + money / 7;
}

int a, b;

void read()
{
    cin >> a >> b;
}

void solve()
{
    // Tổng tiền điện 2 nhà là cost(A + B)
    // Hiệu tiền điện là cost(A) - cost(B) = b
    // Ta duyệt tìm A, rồi tính B = revCost(cost(A+B) - cost(A))
    // Nhưng làm vậy phức tạp -> làm ngược: binary search

    int total = a; // tổng tiền
    int diff = b;  // chênh lệch

    int total_usage = revCost(total); // tổng kWh của cả 2 nhà
    int l = 0, r = total_usage;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int costA = cost(mid);
        int costB = cost(total_usage - mid);
        int delta = llabs(costA - costB);
        if (delta == diff)
        {
            cout << min(costA, costB);
            return;
        }
        if (delta > diff)
            l = mid + 1;
        else
            r = mid - 1;
    }
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    // freopen("DOVUIL.INP", "r", stdin);
    // freopen("DOVUIL.OUT", "w", stdout);
    read();
    solve();
}
