#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =1e3+23;
int tong=0;
void read()
{

}
void solve()
{
    
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int j=1;
    string s=" ";
    while(tong<=N)
    {
        for(int i=1;i<=j;i++)
        s=s+to_string(i);
        tong+=j;

        j++;
    }
    for(int i=1;i<s.size();i++)
    {
        if (s[i]=='1')
        cout << i << " ";
    }
   
    
}
