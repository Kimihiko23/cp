#include <bits/stdc++.h>
//#define int long long
using namespace std;
int n,l,q;
const int N=2e5+23;
int a[N];

void read()
{
    cin >> n >> l >> q;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }

}
void solve()
{
    int q1[N]={0};
    int ans[N]={0};

    deque<int> dq;
    vector<int> sx;
    //sap xep;
    //int nhap;
    for(int i=1;i<=l;i++)
    {
        dq.push_back(a[i]);
    }
    sx.assign(dq.begin(),dq.end());
    sort(sx.begin(),sx.end());
    
    for(int i=1;i<=q;i++)
    {
        cin >> q1[i];
        
        ans[i]=max(ans[i],sx[q1[i]-1]);

    }
    
    for(int i=l+1;i<=n;i++)
    {
        dq.pop_front();
        dq.push_back(a[i]);
        sx.assign(dq.begin(),dq.end());
        sort(sx.begin(),sx.end());
        for(int j=1;j<=q;j++)
        {
        
        
        ans[j]=max(ans[j],sx[q1[j]-1]);

        }


    }
    for(int i=1;i<=q;i++)
    {
        cout << ans[i] << " ";
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
