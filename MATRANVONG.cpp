#include <bits/stdc++.h>
#define int long long
using namespace std;

main()
 {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, x, y;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin >> n >> m;
    

    cin >> x >> y;
    
 
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            
            int distance = max(abs(i - x), abs(j - y));
            cout << distance;
            
            if (j < m - 1) cout << " ";
        }
        cout << endl;
    }
    
 
}