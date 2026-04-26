#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
set<int> a;
map<int,int> mp;
map<int,int> vt;
int n;
void read()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int tam;
        cin >> tam;
        a.insert(tam);
        if(a.size()>2)
        {
            cout << 0;
            exit(0);
        }
        if(mp[tam]==0)
        {
            vt[tam]=i;
        }
        mp[tam]++;
    }
}
void solve()
{
    int ans[2];
    int dem=0;
    for(auto i:a)
    {
        ans[dem]=i;
        dem++;
    }
    //chua gan gia tri ma di so sanh nen sai
    if(a.size()==1)
    {
        cout << 1;
        exit(0);
    }
    if(mp[ans[0]]>1 && mp[ans[1]]>1)
    
    cout <<0;
    else

    if(mp[ans[0]]>mp[ans[1]])
    {
        cout << vt[ans[1]];
    }
    else

    cout << vt[ans[0]];
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
