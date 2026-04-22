#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6+5;
int n;
bool dd[N]={true};
int pre[N]={0};
void sive()
{
    for(int i=2;i*i<N;i++)
    {
        if(dd[i]==true)
        {
            for(int j=i*i;j<N;j+=i)
            {
                dd[j]=false;
            }
        }
    }

}
void read()
{
    cin >> n;
}int ans=0;
void solve()
{
    for(int i=1;i<N;i++)
    {
        dd[i]=true;
    }
    dd[0]=dd[1]=false;
    sive();
    for(int i=1;i<N;i++)
    {
        pre[i]=pre[i-1];
        if(dd[i]==true || i==1)
        {
            pre[i]+=i;
        }
    }
    int k;
    while (n--)
    {
        cin >> k;
        ans=max(ans,pre[k]);
    }
    cout << ans-1;
    

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
    
   
}
