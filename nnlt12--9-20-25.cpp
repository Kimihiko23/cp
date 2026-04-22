#include <bits/stdc++.h>
#define int long long
using namespace std;
void read()
{

}
void solve()
{

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
    string s;
    cin >> s;
    int tong=0;
    for(int i=0;i<s.size();i++)
    {
        tong+=s[i]-'0';
    }
    cout << tong;

    
   
}
