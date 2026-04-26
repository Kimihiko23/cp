#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
multiset<int> a;
int n;
void read()
{
    cin >> n;
    int tam;
    char s;
    while(n--)
    {
        cin >> s >> tam;
        if (s=='+')
        {
            a.insert(tam);
        }
        if(s=='-')
        {
            if (a.find(tam)!=a.end())
            {
                a.erase(a.find(tam));
            }
        }
        if(s=='?')
        {
            auto it1=a.lower_bound(tam);
            auto it2=a.upper_bound(tam);
            auto it3=it1;
            auto it4=it2;
            if (it1!=a.begin())
            {
                it3--;
                cout << *it3 << " ";
            }
            else
            {
                cout << -1 << " ";
            }
            if (it2!=a.begin())
            {
                it4--;
                cout << *it4 << " ";
            }
            else
            {
                cout << -1 << " ";
            }
            if (it1!=a.end())
            {
                cout << *it1 << " ";
            }
            else
            {
                cout << -1 << " ";
            }
            if (it2!=a.end())
            {
                cout << *it2 << " ";
            }
            else
            {
                cout << -1 << " ";
            }
            cout << "\n";
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
