#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =2e6+23;
int n,m;
deque<int> a1,a2;
int a[N];
int dp[N];
void read()
{
    cin >> n >> m;
    for(int i=1;i <= n; i++)
    {
        cin >> a[i];
    }
}
/*void solve() {
    dp[0] = 0;

    deque<int> dq; // lưu j ứng viên

    for (int i = 1; i <= n; i++) {
        // loại bỏ j quá cũ (không nằm trong cửa sổ)
        while (!dq.empty() && dq.front() < i - m + 1)
            dq.pop_front();

        // thêm j = i vào deque theo thứ tự tăng của cost(j)
        while (!dq.empty() && dp[dq.back() - 1] + a[dq.back()] >= dp[i - 1] + a[i])
            dq.pop_back();

        dq.push_back(i);

        // j tốt nhất là dq.front()
        dp[i] = dp[dq.front() - 1] + a[dq.front()];
    }

    cout << dp[n];
}*/
void solve()
{
    dp[0]=0;
    for(int i=1;i <= n; i++)
    {
        if(!a1.empty() && a1.front() < i-m+1)
        {
            a1.pop_front();
        }
        while(!a1.empty() && a[a1.back()]+dp[a1.back()-1] >= a[i]+dp[i-1])
        {
            a1.pop_back();
        }
        a1.push_back(i);
        dp[i]=dp[a1.front()-1]+a[a1.front()];
        
    }
    cout << dp[n];

}
void solve1()
{
    dp[0]=0;
    dp[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        dp[i]=1e18;
        int tam=i-m+1;
        if(tam<1)
        {
            tam=1;
        }
        for(int j=tam;j <= i; j++)
        {
            dp[i]=min(dp[i],dp[j-1]+a[j]);
        }
    }
    cout << dp[n];
}

main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //freopen("NASA.inp","r",stdin);
    //freopen("NASA.out","w",stdout);
    read();
    solve();

   
    
}