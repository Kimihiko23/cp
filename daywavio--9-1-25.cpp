#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+23;
int predp[N]={0},sufdp[N]={0};
vector<int> prelis,suflis;
int a[N];
int n;
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for(int i=1;i<=n;i++) 
        cin >> a[i];
    prelis.push_back(-1e9);
    suflis.push_back(-1e9);
    for(int i=1;i<=n;i++)
    {
        if (a[i]>prelis.back()) 
        {
            prelis.push_back(a[i]);
            predp[i]=prelis.size()-1;
        }
        else
        {
            int pos=lower_bound(prelis.begin(),prelis.end(),a[i])-prelis.begin();
            prelis[pos]=a[i];
            predp[i]=pos;
        }
    }
    for(int i=n;i>=1;i--)
    {
        if (a[i]>suflis.back()) 
        {
            suflis.push_back(a[i]);
            sufdp[i]=suflis.size()-1;
        }
        else
        {
            int pos=lower_bound(suflis.begin(),suflis.end(),a[i])-suflis.begin();
            suflis[pos]=a[i];
            sufdp[i]=pos;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,min(predp[i],sufdp[i])*2-1);
    }
    cout << ans << endl;

    
   
}
