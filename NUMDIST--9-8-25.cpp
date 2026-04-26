#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+21;

main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int tam,n;
        int ans=0;
        cin >> tam >> n;
        for(int i=1;i<=n;i++)
        {
            string s=to_string(i);
            sort(s.begin(),s.end());
            ans+=abs(stoll(s)-i)%mod;
            //cout << ans << " ";
        }
        cout <<ans << "\n";
    }

   
    
}
