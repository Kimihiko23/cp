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
    freopen("testlog.txt","w",stdout);
   // freopen(name".inp","r",stdin); freopen(name".out","w",stdout);w
    srand(time(0));
    int c = 0;
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //tc la so lan test
    for (int tc = 1; tc <= 1000; tc++){
        ofstream fo("input.txt");
        //ofstream la cout

        int n = rand(1, 5), m = rand(1, 5);
        fo << n << " " << m << endl;
        for(int i = 1; i <= m; i++)
        {
            int l = rand(1, n);
            int r = rand(l, n);
            fo << l << " " << r << endl;
        }

        system("BPICTURE--2-6-25.exe");
        system("trau.exe");
        if (system("fc output1.txt output2.txt") == 1) 
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
