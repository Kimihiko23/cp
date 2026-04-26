#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =1e5+23;
int n,s;
int dp[N]={0};

void read()
{

}
void solve()
{
    cin >> n >> s;
    int tam;
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        cin >> tam;
        for(int j=s;j>=tam;j--)
        {
            dp[j]+=dp[j-tam];
            //cout << dp[j] << " ";
        }
        //cout << endl;
    }
    cout << dp[s];
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    solve();
   
    
}
