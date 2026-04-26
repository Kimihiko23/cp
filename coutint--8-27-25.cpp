#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+23;
const int mxab=5e3+1;
vector<int> posa[mxab], posb[mxab];

int n,q;
void read()
{
    cin >> n;
    int tam;
    for(int i=1;i<=n;i++)
    {
        cin >> tam;
        posa[tam].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        
        cin >> tam;
        posb[tam].push_back(i);
    }
    cin >> q ;
}
void solve()
{
    int a,b,c,d;
    while (q--)
    {
        cin >> a >> b >> c >> d;
        int ans=0;
        for(int i=1;i<mxab;i++)
        {
            bool dd=false;
            if (lower_bound(posa[i].begin(),posa[i].end(),a)!=posa[i].end())
            {
                int vt=*lower_bound(posa[i].begin(),posa[i].end(),a);
                if (vt<=b)
                {
                    ans++;
                    continue;
                }
            }
            if (lower_bound(posb[i].begin(),posb[i].end(),c)!=posb[i].end())
            {
                int vt=*lower_bound(posb[i].begin(),posb[i].end(),c);
                if (vt<=d)
                {
                    ans++;
                    continue;
                }
            }
        }
        cout <<ans << "\n";
    }
    
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("COUTINT.inp","r",stdin);
    freopen("COUTINT.out","w",stdout);
    read();
    solve();
}