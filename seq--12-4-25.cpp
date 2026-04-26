#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
int n,q;
multiset<int> a;

void read()
{
    cin >> n;
    for(int i=1;i <= n; i++)
    {
        int tam;
        cin >> tam;
        a.insert(tam);
    }
    cin >> q;
}
void solve()
{
    //cout << q;
    while(q--)
    {
        int cmd,tam;
        cin >> cmd;
        if( cmd == 1)
        {
            cin >> tam;
            a.insert(tam);
        }
        else
        if( cmd == 2)
        {
            cin >> tam;
            a.erase(tam);
        }
        else
        if( cmd == 3)
        {
            cin >> tam;
            auto it=a.upper_bound(tam);
            if( it != a.end() )
            {
                cout << *it << "\n";
            }
            else
                cout << "No\n";
        }
        else
        if( cmd == 4)
        {
            cin >> tam;
            auto it=a.lower_bound(tam);
            if(it != a.begin())
            {
                it--;
                cout << *it << "\n";
            }
            else
            {
                cout << "No\n";
            }
        }
        else
        {
            cout << *a.begin();
            auto it=a.end();
            it--;
            cout << " " << *it << "\n";
        }
    }
  
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
