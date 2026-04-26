#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+23;

main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    int k;
    cin >> k;
    while (k--)
    {
        cin >> n;
        vector<int> a;
        
        a.clear();
        
        int dem[N]={0};
        memset(dem,0,sizeof(dem));
        int tam;
        for(int i=1;i<=n;i++)
        {
            cin >> tam;
            a.push_back(tam);
        }
        
        //bool dd=false;
        int mx1=0,mx2=0;
        int mx3=0;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)
        {
            
            dem[a[i]]++;
            if (dem[a[i]]>=4)
            {
                //dd=true;
                mx1=max(mx1,a[i]);
            }
            
            {
                if (dem[a[i]]>=2)
                {

                    if (a[i]>mx2)
                    {
                        mx3=mx2;
                        mx2=a[i];
                    }
                    
                }
            }
        }
        int mx=0;
        cout << mx2 << " " << mx3  ;
        mx=max(mx3*mx2,mx1*mx1);
        if (mx!=0)
        {
            //cout << mx << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
}
