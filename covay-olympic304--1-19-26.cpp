#include <bits/stdc++.h>
//#define int long long
#define fi first
#define se second
#define pb push_back

using namespace std;

const int N = 1e4+23;
int a[N][N];

map<int,int> mp1;
map<int,int> mp2;
struct query
{
    char ty;
    int x1;
    int y1;
    int x2;
    int y2;
};
vector<query> q;
int n;
void read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        char ty;
        cin >> ty;
        if (ty == '?')
        {
            int a1, a2, a3, a4;
            cin >> a1 >> a2 >> a3 >> a4;
            q.pb({ty, a1, a2, a3, a4});
  
        }
        else
        {
            int x,y;
            cin >> x >> y;
            q.pb({ty, x, y, 0, 0});
     

        }
    }

}
void solve()
{
    for(auto i : q)
    {
        mp1[i.x1];
        mp2[i.y1];
        mp1[i.x2];
        mp2[i.y2];
    }
    int dem = 0;
    for(auto i : mp1)
    {
        dem++;
        mp1[i.fi] = dem;

    }
    dem = 0;
    for(auto i : mp2)
    {
        dem++;
        mp2[i.fi] = dem;

    }
    for(int i = 0; i < n; i++)
    {
        char ty = q[i].ty;
        if (ty == '?')
        {
            int a1 = mp1[q[i].x1], a2 = mp2[q[i].y1], a3 = mp1[q[i].x2], a4 = mp2[q[i].y2];
            int ans=0;
            for(int i1 = a1; i1 <= a3; i1++)
                for(int j1 = a2; j1 <= a4; j1++)
                    ans += a[i1][j1];
            cout << ans << "\n";
        }
        else
        {
            int x = mp1[q[i].x1], y = mp2[q[i].y1];
            a[x][y]++;

        }
    }
}
 main()
 {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
     //freopen("COVAY.inp","r",stdin);
     //freopen("COVAY.out","w",stdout);
     read();
     solve();


 }
