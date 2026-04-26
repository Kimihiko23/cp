#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =2100;
int a[N][N];
int n,m;
void read()
{
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        int tam1,tam2;
        cin >> tam1 >> tam2;
        a[tam1][tam2]++;
        a[tam2][tam1]++;
    }

}
void solve()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout << a[i][j] << " " ;
        }
        cout << "\n";
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
