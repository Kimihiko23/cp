#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N =1e6+23;
bool dd[N];
int n;
vector<int> snt;
void sive()
{
    dd[0]=dd[1]=1;
    for(int i=2;i*i<N;i++)
    {
        if(!dd[i])
        {
            for(int j=i*i;j<N;j+=i)
                dd[j]=1;
        }
    }
}
void read()
{
    cin >> n;
    sive();
}
void solve()
{
    for(int i=2;i<N;i++)
        if(!dd[i])
            snt.pb(i);
    int ans=0;
    //int tam=snt[0]*snt[0]*snt[0]*snt[0];
    for(int i=0;i<snt.size();i++)
    {
        if(snt[i]*snt[i]*snt[i]*snt[i]<=n)
        {
            ans++;
        }
        else
            break;
    }
    cout << ans;
    
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
