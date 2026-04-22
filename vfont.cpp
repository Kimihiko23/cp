#include <bits/stdc++.h>
#define int long long
using namespace std;
int f[30][100];
string s;
int n;
int ans=0;
int cnt[200];
void a(int i)
{
    if (i>n)
    {
        for(int j='a'; j<='z'; j++)
        {
            if (cnt[j]==0)
            {
                return;
            }
        }
        ans++;
        return;
    }
    else
    {
        
        for (int j = 'a'; j <= 'z'; j++)
        {
            cnt[j] += f[i][j];
        }
        a(i + 1);
        for (int j = 'a'; j <= 'z'; j++)
        {
            cnt[j] -= f[i][j];
        }
        a(i + 1);
        
    }

}


void read()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            f[i][s[j]]++;
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
    a(1);
    cout << ans << "\n";
    return 0;
   
}
