#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =2000;
int a[N];
void solve()
{
    for(int i=0;i<N;i++)
    {
        a[i]=1e18;
    }
    a[1]=1;
    int n;
    cin >> n;
    int vt1=1,vt2=1,vt3=1;
    for(int i=2;i<N;i++)
    {
        a[i]=min({a[vt1]*2,a[vt2]*3,a[vt3]*5});
        if (a[i]==a[vt1]*2)
        {
            vt1++;
        }
        if (a[i]==a[vt2]*3)
        {
            vt2++;
        }
        if (a[i]==a[vt3]*5)
        {
            vt3++;
        }
        
    }
    while (n!=0)
    {
        cout << a[n]<< "\n";
        cin >> n;
    }
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
