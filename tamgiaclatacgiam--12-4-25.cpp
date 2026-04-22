#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6;
map<int,int> mpa;
map<int,int> mpb;
map<int,int> mpc;
vector<int> a,b,c;
int n,cmd;
void read()
{
    cin >> n >> cmd;
    int tam;
    for(int i=1; i <= n; i++)
    {
        cin >> tam;
        a.pb(tam);
        mpa[tam]++;
    }
    for(int i=1; i <= n; i++)
    {
        cin >> tam;
        b.pb(tam);
        mpb[tam]++;
    }
    for(int i=1; i <= n; i++)
    {
        cin >> tam;
        c.pb(tam);
        mpc[tam]++;
    }
}
void solve()
{
    int ans1,ans2,ans3;
    ans1=ans2=ans3=0;
    sort(c.begin(),c.end());
    for(int i=0;i < n; i++)
    {
        ans1+=mpa[c[i]]*mpb[c[i]];
    }
    for(int i=0;i < n; i++)
    {
        for(int j=0;j < n; j++)
        {
            if(a[i]!=b[j])
            {
                if(a[i]*2 > b[j])
                {
                    ans2+=mpc[a[i]];
                }
                if(b[j]*2 > a[i])
                {
                    ans2+=mpc[b[j]];
                }
            }
            else
            {
                ans2 += upper_bound(c.begin() , c.end() , a[i] + b[j] - 1) - lower_bound(c.begin() , c.end() , abs(a[i] - b[j]) + 1);
            }
        }
    }
    for(int i=0;i < n; i++)
    {
        for(int j=0;j < n; j++)
        {
            
                ans3 += upper_bound(c.begin() , c.end() ,a[i] + b[j] - 1) - lower_bound(c.begin() , c.end() , abs(a[i] - b[j]) + 1);
           
        }
    }
    if(cmd==1)
    {
        cout << ans1;
    }
    else
    if(cmd==2)
    {
        cout << ans2;
    }
    else
    if(cmd==3)
    {
        cout << ans3;
    }
    
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
