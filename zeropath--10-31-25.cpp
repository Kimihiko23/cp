#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e7+23;
map<pair<int,int>,int> kq;
int n;
void read()
{
    cin >> n;
}   
queue<int> a;
bool dd[N]={0};
void bfs()
{
    a.push(n);
    while(!a.empty())
    {
        int u=a.front();
        a.pop();
        for(int i=1;i<=sqrt(u);i++)
        {
            if(u%i==0)
            {
                int b=u/i;
                int v=(i-1)*(b+1);
                if(v>=0 && dd[v]==0)
                {
                    dd[v]=1;
                    a.push(v);
                }
            }
        }
    }
}
void solve()
{
    bfs();
    int dem=0;
    for(int i=0;i<n;i++)
        if(dd[i]) dem++;
    cout << dem << "\n";
    for(int i=0;i<n;i++)
        if(dd[i]) cout << i << " ";
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
