#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6;
string s;
int tong;
bool dd=false;
void read()
{
    cin >> s;
}

void solve()
{
    for(int i=0;i<s.size();i++)
    {
        tong+=s[i]-'0';
        if (s[i]=='0')
        {
            dd=true;
        }
    }
    if (!dd || tong%3!=0)
    {
        cout << "-1";
    }
    else
    {
        sort(s.begin(), s.end(), greater<char>());
        cout << s;
    }
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    read();
    solve();
    
   
}
