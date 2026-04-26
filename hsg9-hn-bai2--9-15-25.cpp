#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =1e5+23;
int dd[N]={0};
string s="";
int n;
void read()
{
    cin >> n;
    cin.ignore();
    for(int i=1;i<=n;i++)
    {
      getline(cin,s);
      int dem=1;
      for(int j=0;j<s.size();j++)
      {
        
        if (s[j]==' ')
        {
            
            dem++;
        }
        if (s[j]=='X')
        {
            dd[dem]++;
        }
        
      } 
      
    }
    
}
void solve()
{
    int mx=0;
    int somx=0;
    vector<int> ans;
    int mxvote;
    for(int i=1;i<=n;i++)
    {
        
        if (dd[i]==mx)
        {
            somx++;
            ans.push_back(i);
        }
        if (dd[i]>mx)
        {
            somx=1;
            mx=dd[i];
            ans.clear();
            ans.push_back(i);
        }

    }
    cout << somx << " " << mx << "\n";
    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i] << " ";
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
