#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 5;
int n;

void read() {
    cout << "If you are male, enter 1. If you are female, enter 0.\n";
    cout << "If you enter something else, please try again.\n";
    cout << "Enter your gender: ";
    cin >> n;
}

void solve() {
    system("cls"); // clear screen (Windows)
    if (n == 1) {
        cout << "You're gay.";
    }
    else if (n == 0) {
        cout << "Wish you a sweet October 20th, as lovely as your smile,\n"
                "and as happy as the joy you bring to everyone!\n"
                "Thank you for being such a wonderful person!\n"
                "May your October 20th be filled with love and beautiful memories.\n"
                "Be loved, be lucky, and keep shining like the sun!";
    }
    else {
        cout << "Wtf? Gay maybe? Anyway, happy October 20th! <()";
    }
}

int32_t main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    cout.tie(0);
    read();
    solve();
}
