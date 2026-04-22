#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=6000;
string s[N];
int n,m;
void read()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> s[i];
}
void solve()
{
    for(int i=n;i>=1;i--)
    {
        int dd[26]={0};
        bool dd1=true;
        for(int j=0;j<s[i].size();j++)
            {
                dd[s[i][j]-'a']++;
                if(dd[s[i][j]-'a']>1) 
                {
                    dd1=false;
                }
            }
        if(dd1)
        {
            cout << n-i;
            break;
        }
    }

}
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    freopen("DELROW.INP", "r", stdin);
    freopen("DELROW.OUT", "w", stdout);
    read();
    solve();
    
   
}
