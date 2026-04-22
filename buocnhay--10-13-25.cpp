#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+7;
int a[N],n;
int dp[N]={0};
int nx[N]={0};
int q;
void read()
{ 
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> a[i];
}
void solve()
{
    stack<int> st;
    for(int i=n;i>=1;i--)
    {
        while(!st.empty() && a[st.top()]<=a[i]) st.pop();
        if(!st.empty())
        nx[i]=st.top();
        st.push(i);
    }
    for(int i=n;i>=1;i--)
    {
        if (dp[nx[i]] != -1)
            dp[i] = dp[nx[i]] + 1;
        else
            dp[i] = 0;
    }
    while (q--)
    {
        int x; cin >> x;
        cout << dp[x]-1 << "\n";
    }
    

}
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    read();
    solve();
    
   
}
