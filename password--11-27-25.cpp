#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6;
map<string,int> mp;
map<string,bool> used;
int n;
vector<string> v;
void read()
{
    cin >> n;
    for(int i=1;i<=n; i++)
    {
        string s;
        cin >> s;
        v.pb(s);
        mp[s]++;
        used[s]=true;

    }
}

void solve()
{
    for(auto i:v)
    {
        int tam=0;
        string s=i;
        for(auto &j:used)
        {
            j.se=true;
        }
        for(int j=0;j<s.size();j++)
        {
            for(int k=j;k<s.size();k++)
            {
                
                string t=s.substr(j,k-j+1);
                //cout << t << " ";
                if( used[t])
                {
                    tam+=mp[t];
                    used[t]=false;
                }
            }
        }
        cout << tam-1 << "\n";
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
