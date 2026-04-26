#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,t;
const int N=8e3;
const int mx=8000;
unordered_set<int> fib;

void read()
{
    cin >> t;
}

void fibo() 
{
    int f1=1,f2=3;
    fib.insert(f1);
    fib.insert(f2);
    while (true) {
        int f3=f1+f2;
        if (f3>mx) break;
        fib.insert(f3);
        f1=f2;
        f2=f3;
    }
}

void solve() {
    while (t--) {
        cin >> n;
        queue<int> a;
        for(int i=1;i<=n;i++) {
            a.push(i);
        }
        
        while (a.size()!=1) {
            int k=a.size();
            queue<int> tmp;
            for(int i=1;i<=k;i++) {
                int x=a.front(); a.pop();
                if (fib.find(i)==fib.end()) { 
                    tmp.push(x); 
                }
            }
            a=tmp;
        }
        cout << a.front() << "\n";
    }
}

main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    read();
    fibo();
    solve();
}
