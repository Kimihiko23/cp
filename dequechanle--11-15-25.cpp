#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
int n;
deque<int> a;
void read()
{
    cin >> n;
    int tam;
    for(int i=1;i<=n;++i)
    {
        cin >> tam;
        if (tam%2==0)
        {
            a.push_back(tam);
        }
        else
            a.push_front(tam);
    }
}
void solve()
{
    for(int i=1;i<=n;++i)
    {
        int tam=a.front();
        a.pop_front();
        cout << tam << " ";
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
