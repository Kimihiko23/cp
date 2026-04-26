#include <bits/stdc++.h>
#define int long long
using namespace std;

main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a[200]={0};
    string s;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> s;
    int mx=0;
    for(int i=0;i<s.size();i++)
    {
        a[s[i]]++;
        mx=max(mx,a[s[i]]);

    }
    for(int i=0;i<=199;i++)
    {
      if (a[i]==mx)
      {
        cout << char(i) << " " <<a[i];
        break;
      }
    }
    
}
