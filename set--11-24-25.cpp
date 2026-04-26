#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
set<int> a;
int n;
void read()
{
    cin >> n;
    while(n--)
    {
        char s;
        int tam;
        cin >> s >> tam;
        if(s=='+')
        {
            a.insert(tam);
        }
        else
        if(s=='-')
        {
            a.erase(tam);
        }
        else
        {
            if(a.find(tam)!=a.end())
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
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
    read();
    solve();

   
    
}
