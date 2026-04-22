#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;


mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());


ll rand(ll l, ll r){
    return uniform_int_distribution <int> (l, r) (rd);
}


main()
{
   // freopen(name".inp","r",stdin); freopen(name".out","w",stdout);w
    srand(time(0));
    int c = 0;
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //tc la so lan test
    for (int tc = 1; tc <= 1000; tc++){
        ofstream fo("input.txt");
        //ofstream la cout

        int n = rand(1, 50), m = rand(1, 50), k = rand(1, 1000*100);
        fo << n << endl << m << endl << k << endl;
        for (int i = 1; i<=n; i++)
        {
            for (int j = 1; j<=m; j++)
            {
                int a = rand(1, 1000);
                fo << a << endl;
            }
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
