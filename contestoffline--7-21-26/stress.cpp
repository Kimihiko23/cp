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
    for (int tc = 1; tc <= 10; tc++){
        ofstream fo("input.txt");
        //ofstream la cout

        int t = rand(1, 10);
        fo << t << endl;
        while(t--)
        {
            int n = rand(1, 50);
            fo << n << endl;
            for (int i = 1; i<=n; i++)
            {
                fo << rand(1, 100) << " ";
            }
            fo << endl;
            for (int i = 1; i<=n; i++)
            {
                fo << rand(1, 100) << " ";
            }
            fo << endl;
        }

        system("b1.exe");
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
