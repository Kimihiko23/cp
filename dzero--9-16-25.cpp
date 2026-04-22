#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+23;
int dp[N]={0};
vector<int> uoc[N];
void read()
{

}
void solve()
{
    for(int i=2;i<N;i++)
    {
        for(int j=i*2;j<N;j+=i)
        {
            uoc[j].push_back(i);
        }

    }
    /*for(auto x:uoc[2])
    {
        cout << x << " ";
    }*/
    dp[1]=0;

    for(int i=1;i<N;i++)
    {
        dp[i]=dp[i-1]+1;
        for(int j=0;j<uoc[i].size();j++)
        {
            {
            int ans=max(i/uoc[i][j],uoc[i][j]);
            //cout << ans << " ";
            dp[i]=min(dp[i],dp[ans]+1);
            }
            
        }
        
    }
    int t;
    cin >> t;
    while (t--)
    {
        int tam;
        cin >> tam;
        cout << dp[tam] << "\n";

    }
    
}
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
    
   
}
