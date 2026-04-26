#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =1e5+23;
stack<char> a;
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DAYNGOAC.inp","r",stdin);
    freopen("DAYNGOAC.out","w",stdout);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        bool dd=false;
        for(int i=0;i<s.size();i++)
        {
            if (s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                a.push(s[i]);
                //continue;
            }
            if (s[i]==')')
            {
                if (a.top()!='(' || a.empty())
                {
                cout << "FALSE\n";
                dd=true;
                break;
                }
                else
                {
                    a.pop();
                }
            }
            if (s[i]==']')
            {
                if (a.top()!='[' || a.empty())
                {
                cout << "FALSE\n";
                dd=true;
                break;
                }
                else
                {
                    a.pop();
                }
                
            }
            if (s[i]=='}')
            {
                if (a.top()!='{' || a.empty())
                {
                cout << "FALSE\n";
                dd=true;
                break;
                }
                else
                {
                    a.pop();
                }
                
            }
        }
        if (!dd && a.empty())
        {
            cout << "TRUE\n";
        }
        if (!dd && !a.empty())
        {
            cout << "FALSE\n";
        }
        
    }
   
    
}
