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
    for (int tc = 1; tc <= 100; tc++){
        ofstream fo("input.txt");
        //ofstream la cout

        int n = rand(2, 100);
        fo << n << endl;
        for (int i = 1; i <= n; i++)
        {
            fo << rand(-50000, 50000) << " ";
        }

        system("sd2eq--7-14-26.exe");
        system("trau.exe");
        if (system("fc ac.out output.txt") == 1) 
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
