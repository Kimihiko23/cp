#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=5e5+5;

int q;
int n;
void read()
{
    cin >> q;

}

void solve()
{
    int l[N]={0}, r[N]={0},
    mn[N]={0};
    vector<int> left,right;
    string s;
    while(q--)
    {
        cin >> n >> s;
        left.clear();
        right.clear();
        int pre[N]={0};
        int suf[N]={0};
        //l.clear();
        s=" "+s;
        for(int i=1; i<=n; i++)
        {

            r[i]=r[i-1];
            l[i]=l[i-1];
            if(s[i]=='>')
            {
                r[i]++;
            }
            if(s[i]=='<')
            {
                l[i]++;
            }
        }
        for(int i=1; i<=n; i++)
        {
            mn[i]=min(r[i-1], l[n]-l[i]);
        }
        right.push_back(0);
        left.push_back(0);
        for(int i=1;i<=n;i++)
        {
            if (s[i]=='>')
            {
                right.push_back(i);
            }
            
        }
        for(int i=1;i<right.size();i++)
        {
            pre[i]=pre[i-1]+right[i];
        }
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='<')
            {
                left.push_back(i);
            }
        }
        for(int i=left.size()-1;i>=1;i--)
        {
            suf[i]=suf[i+1]+left[i];
        }
        
        
    }
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
