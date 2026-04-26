#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =50+27;

main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int q;
    cin >> q;
    while (q--)
    {
        int n,x;
        cin >> n >> x;
        double dp[N]={0};
        int a[N]={0};
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
        }
        dp[0]=x;
        for(int i=1;i<=n;i++)
        {
            dp[i]=dp[i-1];
            for(int j=1;j<i;j++)
            {
                dp[i]=max(dp[i],
                    dp[j-1]*((double)a[i]/a[j])-dp[j-1]*0.02);
            }
        }
        cout << fixed << setprecision(5) <<  dp[n] << "\n";

    }
    
}
