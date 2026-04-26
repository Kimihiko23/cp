#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
string s;
void read()
{
    cin >> n >> k;
    cin >>s;
}
void solve()
{
    if (n>k)
    {
    
    bool dd=true;
    while (k-- && dd)
    {
        for(int i=0;i<s.size()-1;i++)
        {
            if ((s[i]=='1'&&s[i+1]=='0'&&
                s[i-1]=='1' && i!=0) || (i==0
                && s[i]=='1'&&s[i+1]=='0'))
            {
                swap(s[i],s[i+1]);
                break;
            }
            else
            {
                if (i==s.size()-2)
                {
                    dd=false;
                    break;
                }
            }
            
        }
    }
        
    }
    else
    {
        int mn=1e9;
        int tong1=0,tong2=0;
        for(int i=0;i<s.size();i++)
        {
            if (s[i]=='1')
            {
                tong1++;
            }
            else
            {
            tong2++;
            }
            
        }
        mn=min(tong1,tong2);
        cout << mn*2;
        exit(0);
    }
    
    int ans=0;
    for(int i=0;i<s.size()-1;i++)
    {
        if (s[i]!=s[i+1])
        {
            ans++;
        }
    }
    cout << ans;
}
void test()
{
    int dem=0;
    bool dd=true;
    while (dd)
    {
        for(int i=0;i<s.size()-1;i++)
        {
            if (s[i]=='1'&&s[i+1]=='0'&&
                s[i-1]=='1' && i!=0)
            {
                swap(s[i],s[i+1]);
                dem++;
                break;
            }
            else
            {
                if (i==s.size()-2)
                {
                    dd=false;
                    break;
                }    
            
            }
        }
    }
    cout << dem << " " <<s;
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
    //test();
    
}
