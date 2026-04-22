#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6;
int dem=0;
string st;
set<string> ans;
bool dd[N];
void dequy(string s)
{
    if (s.size()==st.size())
    {
        ans.insert(s);
        return;
    }    
    for(int i=0;i<st.size();i++)
    {
        if(!dd[i])
        {
            dd[i]=1;
            dequy(s+st[i]);
            dd[i]=0;
        }
    }
}
void read()
{
    cin >> st;
}

void solve()
{
    dequy("");
    cout << ans.size() << "\n";
    for(auto i:ans)
    {
        cout << i << "\n";
    }
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    read();
    solve();
    
   
}
