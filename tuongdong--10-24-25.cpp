#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N =1e5+23;
//int a[500]={0};
int mon[N][6];
int n;

void read()
{

}
void solve()
{
    while(cin >> n && n!=0)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=5;j++)
            {
                cin >> mon[i][j];
            }
        }
        bool dd=true;
        int mx=-1e18;
        int a[600]={0};
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            // a={0};
            int a[600]={0};
                for(int j=1;j<=5;j++)
                {
                    a[mon[i][j]]++;
                }
            for(int j=1;j<=n;j++)
            {
                if (i==j) continue;
                int dem=0;
                for(int j1=1;j1<=5;j1++)
                {
                    if (a[mon[j][j1]]>=1)
                    {
                        dem++;
                    }
                }
                if(dem==5)
                {
                ans++;
                }
            }
        }
        if(ans==1)
        {
            cout << n;
        }
        else
        cout << ans << "\n";
    }
}

main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    read();
    solve();
   
    
}
