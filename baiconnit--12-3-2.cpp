#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
vector<string> s{"ab","ba","aba","bab"};
string s1;
void read()
{
    cin >> s1;
    

}
string ans;
void solve()
{
    bool flag = false;
    char pre=s1[0];
    int dem=1;
    for(int i=1; i<s1.size(); i++)
    {
        if( s1[i]==pre)
        {
            dem++;
            if(dem>=3)
            {
                flag=true;
                break;
            }
        }
        else
        {
            pre=s1[i];
            dem=1;
        }
    }
    if(flag)
    {
        cout << "tancute";
        exit(0);
    }
    
    while(s1.size()!=0)
    {
        
        for(int i=s.size()-1; i >= 0 ; i--)
        {
            
            auto it=s1.find(s[i]);
            if(it == 0)
            {
                if(i>=2)
                s1.erase(0,3);
                else
                s1.erase(0,2);
                ans=ans+to_string(i);
                
                
            }

            
            
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
