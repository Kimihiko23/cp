#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
multiset<int> a;
map<int,int> mp;
int n;
int b[N];
int dem=0;
void read()
{
    cin >> n;
    for(int i=1;i <= n; i++)
    {
        cin >> b[i];
        if(mp[abs(3-b[i])]!=0)
        {
            if(mp[abs(3-b[i])]>mp[b[i]]+1)
            {
                dem+=mp[b[i]]+1;
                mp[b[i]]=-1;
                
            }
            else
            {
                dem+=mp[abs(3-b[i])];
                mp[abs(3-b[i])]=0;

            }
            cout << "gay ";
        }
        mp[b[i]]++;
    }
}
void solve()
{
    cout << n-dem;
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
