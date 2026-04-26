#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =3e6+23;
int a[N];
int pre[N];
int l,r;
int n;
void read()
{
    cin >> n >> l >> r;
    pre[0]=0;
    for(int i=1;i <= n; i++)
    {
        cin >> a[i];
        pre[i]=pre[i-1]+a[i];
    }
}
void solve()
{
    deque<int> dq;
    int ans=-1e18;
    int tam=0;
    deque<int> wait;
    for(int i=0;i <= n; i++)
    {
        if(!dq.empty() && i-dq.front() > r)
            dq.pop_front();
        if(!dq.empty() && i-dq.front() >= l)
        {
            ans=max(ans,pre[i]-pre[dq.front()]);
        }
        wait.push_back(i);
        while(!wait.empty() && i-wait.front()>=l)
        {
            while(!dq.empty() && pre[dq.back()]>=pre[wait.front()])
            {
                dq.pop_back();
            }
            dq.push_back(wait.front());
            wait.pop_front();
        }   
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
