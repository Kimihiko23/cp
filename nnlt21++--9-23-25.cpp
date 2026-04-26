#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =1e5+23;
void read()
{

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
    int n,m;
    cin >> n >> m;
    vector<int> a;
    int tam;
    n*=m;
    for(int i=1;i<=n;i++)
    {
        cin >> tam;
        a.push_back(tam);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++)
    {
        cout << a[i]<< " ";
        if (i!=0 && (i+1)%m==0)
        {
            cout << "\n";
        }
    }
   
    
}
