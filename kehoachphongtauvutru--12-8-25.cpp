#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=4e6;
int a[N];
deque<int> dq;
int n,k;
void push(int val)
{
    if(!dq.empty())
    //auto it=dq.back();
    while(!dq.empty() && dq.back()>=val)
    {
        dq.pop_back();
    }
    dq.push_back(val);
}
void read()
{
    cin >> n >> k;
    for(int i=1;i <= n; i++)
    {
        cin >> a[i];
    }
    
}

void solve()
{
    int ans=0;
    int tam=1;
    for(int i=1;i <= n ; i++)
    {
        while(!dq.empty() && a[dq.back()] >= a[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if(dq.front() == i - k + 1)
        {
            dq.pop_front();
        }
    

    }
    cout << ans;
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
