#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back

using namespace std;

const int N = 1e3+23;
const int N1 = 1e6+23;
int pre[N][N];
int a[N][N];
int ans[N1];
int n, m, k;
void read()
{
    cin >> n >> m;
    int x;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            a[i][j] = x;
            pre[i][j] = x + pre[i - 1][j] + pre[i][j - 1]  - pre[i - 1][j - 1];
            //cout << pre[i][j] << " ";
        }
        //cout << "\n";
    }
    cin >> k;
    //cout << "\n";
}
void sub1()
{
    for(int i = 1; i <= k; i++)
    {
        int st,ed;
        cin >> st >> ed;
        int ans = 0;
        for(int j = st; j <= ed; j++)
        {
            int mn = 1e18;
            int mx = -1e18;
            int dem = 0;
            for(int z = j; z >= st; z--)
            {
                mn = min(mn, a[z][1]);
                mx = max(mx, a[z][1]);
                if(mx - mn > 1)
                {
                    break;
                }
                else
                {
                    dem++;
                }
            }
            ans = max ( ans,dem);
            dem = 0;
            for(int z = j; z <= ed; z++)
            {
                mn = min(mn, a[z][1]);
                mx = max(mx, a[z][1]);
                if(mx - mn > 1)
                {
                    break;
                }
                else
                {
                    dem++;
                }
            }
            ans = max ( ans,dem);
        }
        cout << ans << "\n";

    }
}
void sub2()
{
    vector<pair<int, pair<int, int>>> query;
    for(int i = 1; i <= k; i++)
    {
        int st,ed;
        cin >> st >> ed;
        query.pb({st,{ed,i}});
        //query.push_bacK
    }
}
 main()
 {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
     //freopen("BANGSO.inp","r",stdin);
     //freopen("BANGSO.out","w",stdout);
     read();
     if (m == 1)
     sub1();

 }
