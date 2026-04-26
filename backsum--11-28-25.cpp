#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N =1e5+23;
int n,x;
vector<char> v{'1','2','3','4','5','+','-'};
void dequy(string s)
{
    if(s.size()==n*2-1)
    {
        int sum=0;
        string s1='+'+s+'+';
        string tmp="";
        int dd=1;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]>='1'&&s1[i]<='5')
            {
                tmp+=s1[i];
            }
            else
            {
                //sum+=stoi(tmp);
                if (i!=0)
                {
                    sum+=dd*stoi(tmp);
                }
                if(s1[i]=='-')
                {
                    dd=-1;
                }
                else
                {
                    dd=1;
                }
                
                tmp="";
            }
            
        }
        if(sum==x)
        {
            for(int i=0;i<s.size();i++)
            {
                cout << s[i] << " ";
            }
            cout << "\n";
        }
        return;
    }
    for(auto i:v)
    {
        if(!s.empty())
        {
        if (s[s.size()-1]=='+'||s[s.size()-1]=='-')
        {
            if(i>='1'&&i<='5')
            {
                dequy(s+i);
            }
        }
        else
        {
            if(i=='+'||i=='-')
            {
                dequy(s+i);
            }
        }
        }
        else
        {
            if(i>='1'&&i<='5')
            {
                dequy(s+i);
            }
        }
    }
}
void read()
{
    cin >> n >> x;

}
void solve()
{
    dequy("");
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
