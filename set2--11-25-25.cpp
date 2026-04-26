#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
multiset<int> mul;
int n;
void read()
{
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        char s;
        int a;
        cin >> s;
        if (s!='?')
        cin >> a;
        if (s=='+')
        mul.insert(a);
        else
        if (s=='-')
        {
            auto it=mul.find(a);
            if (it!=mul.end())
            mul.erase(it);
        }
        else
        {
            if (mul.empty())
            {
                cout << "-1 -1 -1 -1\n";
            }
            else
            if (mul.size()==4)
            {
                cout << *mul.rbegin() << " " << *mul.begin()++ << " " << *mul.end()-- << " " << *mul.end() << "\n";
            }
            else
            if (mul.size()==2)
            {
                cout << *mul.begin() << " -1 -1 " << *mul.end() << "\n";
            }
            else
            if (mul.size()==3)
            {
                cout << *mul.rbegin() << " " << *mul.begin()++ << " -1 " << *mul.end() << "\n";
            }
            else
            {
                cout << *mul.begin() << " -1 -1 -1\n";
            }
        }
    }
}
void solve()
{
    
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //ac code at codeforce this code is wrong =))
    read();
    solve();

   
    
}
