#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+23;
vector<pair<int,pair<int,int>>> a;
int dp[N]={0};
int n;
void read()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int tam1,tam2,tam3;
        cin >> tam1 >> tam2 >> tam3;
        a.push_back({tam1,{tam2,tam3}});
    }
    sort(a.begin(),a.end());

}
void solve()
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        dp[i]=a[i].second.second;
        //cout << dp[i] << " ";
        for(int j=0;j<i;j++)
        {
            if (a[i].first>=a[j].second.first)
            {
                dp[i]=max(dp[i],dp[j]+a[i].second.second);
            }
            //cout << dp[i] << " ";
        }
        //cout << "\n";
        ans=max(ans,dp[i]);
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
