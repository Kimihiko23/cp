#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;


mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());


ll rand(ll l, ll r){
    return uniform_int_distribution <int> (l, r) (rd);
}

int n = rand(1, 15);
bool dd[100];
vector<int> s;
void randhoanvin(int cnt)
{
    if(cnt == n)
        return;
    int nx = rand(1, n);
    while(dd[nx])
    {
        nx = rand(1, n);
    }
    dd[nx] = 1;
    s.push_back(nx);
    randhoanvin(cnt + 1);
}
main()
{
   // freopen(name".inp","r",stdin); freopen(name".out","w",stdout);w
    srand(time(0));
    int c = 0;
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //tc la so lan test
    for (int tc = 1; tc <= 1; tc++){
        ofstream fo("input.txt");
        //ofstream la cout
        memset(dd, 0, sizeof(dd));
        fo << n << endl;
        for (int i = 1; i<=n; i++)
        {
            fo << rand(1, (int)1e2) << " ";
        }
        fo << endl;
        randhoanvin(0);
        for(auto i : s)
        {
            fo << i << " ";
        }

        system("ac.exe");
        system("trau.exe");
        if (system("fc a1.out output.txt") == 1) 
        {
            cout << "Siesta hate you\n";
            exit(0);
        }
        else
        {
            cout << "Siesta love u\n";
        }

    }
    return 0;
}
