#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+23;
int n,x;
void read()
{
  
}
void solve()
{
    int t;
    cin >> t;
    int n,m,x,y;
    while (t--)
    {
        int n,m;
        int tam1,vt,oldtam=-1;
        cin >> n >> m;
        int ans=m;
        int dd1=1,dd2=0;
        for(int i=1;i<=n;i++)
        {
            
            cin >> tam1 >> vt;
            if (tam1%2==0 && vt==dd1)
            {
                ans--;
                swap(dd1,dd2);
            }
            else
            {
                if (tam1%2==1 && vt==dd2)
                {
                    ans--;
                    swap(dd1,dd2);
                }
            }
            

        }
        cout << ans << "\n";

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
