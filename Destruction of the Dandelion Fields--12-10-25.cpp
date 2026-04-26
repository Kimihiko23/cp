#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
vector<int> odd;
int q;
void read()
{
    cin >> q;
}
void solve()
{
    int n,ans=0;
    cin >> n;
    int dem1=0,dem2=0;
    int tam;
    int sum=0;
    odd.clear();
    for(int i=1;i <= n;i++)
    {
        cin >> tam;
        if(tam%2==0)
        {
            sum+=tam;
        }
        else
        {
            odd.push_back(tam);
        }
    }
    sort(odd.begin(),odd.end());
    int l=0,r=odd.size()-1;
    if(!odd.empty())
    {
        ans+=sum;
    }
    else
    {
        cout <<"0\n";
        return;
    }
    ans+=odd[r];
    r--;
    while(l<r)
    {
        
        ans+=odd[r];
        r--;
        l++;
        
    }
    cout << ans << "\n";
    
    
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    read();
    while(q--)
    solve();

   
    
}
