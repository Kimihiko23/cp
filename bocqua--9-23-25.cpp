#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+23;
int dp[N][3]={0};
int n,k,x;
int a[N];
void read()
{
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+1+n);

}
void solve()
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=2;j++)
        {
            int l,r,mid;
            l=1;
            r=i;
            int vt=-1;
            while(l<=r)
            {
                mid=(l+r)/2;
                if((a[i]-k)<=a[mid])
                {
                    vt=mid;
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            //cout << vt << " ";
            if (vt!=-1)
            {
                dp[i][j]=max(dp[i-1][j],dp[vt-1][j-1]+(i-vt+1));
            }
            ans=max(ans,dp[i][j]);
        }
    }
    
    cout << ans;
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