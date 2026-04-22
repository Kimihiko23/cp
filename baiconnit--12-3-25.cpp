#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
int dp[1000005];
bool get(int id, string sub) 
{
    int l = id - sub.size() + 1;
    if (l <= 0) return 0;
    string t = s.substr(l, sub.size());
    return sub == t;
}
main()
{
    dp[0] = 1;
    cin >> s;
    s = " " + s;
    int n = s.size() - 1;
    ;
    for (int i = 1; i <= n; i++) 
    {
        if (get(i, "ab")) dp[i] |= dp[i - 2];
        if (get(i, "ba")) dp[i] |= dp[i - 2];
        if (get(i, "aba")) dp[i] |= dp[i - 3];
        if (get(i, "bab")) dp[i] |= dp[i - 3];

    }
    if (dp[n] == 0)
        cout << "tancute";
    else 
    {
        int i = n;
        stack<int> st;
        while (i > 0) {
            if (get(i, "ab") && dp[i - 2]) i -= 2, st.push(0);
            if (get(i, "ba") && dp[i - 2]) i -= 2, st.push(1);
            if (get(i, "aba") && dp[i - 3]) i -= 3, st.push(2);
            if (get(i, "bab") && dp[i - 3]) i -= 3, st.push(3);
        }
        while (st.size()) cout << st.top(), st.pop();
    }
}