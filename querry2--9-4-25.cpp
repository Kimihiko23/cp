#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+23;
vector<int> a;
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int q;
    cin >> q;
  
    int l=0,r=n-1,mid;
    int ans=-1;
    while(q--)
    {
        int tam;
        cin >> tam;
        ans=-1;
        mid=(l+r)/2;
        l=0;
        r=n-1;
        while (l<=r)
        {
            mid=(l+r)/2;
            if(a[mid]<=tam)
            {
                ans=a[mid];
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        //if ans!=-1)
        cout << ans << "\n";
    }
    
   
}
