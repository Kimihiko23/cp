#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 5;
int mod = 2e9 + 11;
int base = 256;
string a , b;
int pre[N] , p[N];

/// p[i] = base ^ i

int add(int a , int b)
{
    return (a + b) % mod;
}

int mul(int a , int b)
{
    return (a * b) % mod;
}

int sub(int a , int b)
{
    return ((a - b) % mod + mod) % mod;
}

int f(int l , int r)
{
    return sub(pre[r] , mul(p[r - l + 1] , pre[l - 1]));
}


main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> a;
    int n = a.size();
    a = " " + a;

    cin >> b;
    int m = b.size();
    b = " " + b;

    /// a[1...n] , b[1...m]

    /// p[i] = base ^ i
    p[0] = 1;
    for(int i = 1 ; i <= max(n , m) ; i++)
    {        
        p[i] = mul(p[i - 1] , base);
        cout << p[i] << " ";
    }

    for(int i = 1 ; i <= n ; i++)
    {      
        pre[i] = add(mul(pre[i - 1] , base) , a[i]);
        // cout << pre[i] << " ";
    }


    int H = 0; /// H là mã của hash của nguyên xâu B

    for(int i = 1 ; i <= m ; i++)
        H = add(mul(H , base) , b[i]);

    for(int i = 1 ; i + m - 1 <= n ; i++)
    {
        /// a[i...i+m-1] = b[1...m]
        if(f(i , i + m - 1) == H)
            cout << i << " ";
    }



}
