#include<bits/stdc++.h>
using namespace std;

#define ii pair < int , int >

const int N = 3e5 + 5;
int n , S;
ii a[N];

main(){
   freopen("tan.inp","r",stdin);
   freopen("tan.out","w",stdout);
   ios::sync_with_stdio(0);
   cin.tie(0);
   cin >> n >> S;
   int dp[n + 1][S + 1];
   memset(dp , -0x5f , sizeof(dp));

   for(int i = 1 ; i <= n ; i++)
        cin >> a[i].first >> a[i].second;


   for(int i = 1 ; i <= n ; i++)
   {
       if(a[i].first <= S)
            dp[i][a[i].first] = a[i].second;


       for(int j = a[i].first ; j <= S ; j++)
       {
           for(int k = 1 ; k <= i - 1 ; k++)
                if(a[i].second > a[k].second)
                        dp[i][j] = max(dp[i][j] , dp[k][j - a[i].first] + a[i].second);
       }
   }

   int ans = -1e9;
   for(int i = 1 ; i <= n ; i++)
        ans = max(ans , dp[i][S]);

    if(ans < 0)
        cout << -1;
    else
        cout << ans;

}
