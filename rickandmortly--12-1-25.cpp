#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N=1e6;
int n;
vector<string> s{"Never","Gonna","Give","You","Up","Never","Gonna","Let","You","Down","Never","Gonna","Run","Around","And","Desert","You","Never","Gonna","Make","You","Cry","Never","Gonna","Say","Goodbye","Never","Gonna","Tell","A","Lie","And","Hurt","You"};
void read()
{
    cin >> n;
}

void solve()
{
    cout << s[n-1];
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
