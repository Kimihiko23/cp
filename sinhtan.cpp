#include<bits/stdc++.h>
using namespace std;

#define int long long


mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int rand(int l, int h) /// hàm random từ l đến h
{
    return uniform_int_distribution <int> (l, h) (rng);
}

main()
{
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int test = 1 ; test <= 100 ; test++)
    {
        ofstream cout("tan.inp");

        /// n ^ 2 * S
        int n = rand(1 , 100);
        int S = rand(1 , 100);
        cout << n << " " << S << endl;

        for(int i = 1 ; i <= n ; i++)
            cout << rand(1 , 1000) << " " << rand(1 , 1000) << endl;
        cout << endl;

        system("tan.exe");
        /// chạy code trâu
        system("trautan.exe");

        /// fc = file compare
        if(system("fc tan.out trautan.out") == 1)
            exit(0);

    }

}


