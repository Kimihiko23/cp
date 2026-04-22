#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;
int n , q;
int a[N];

struct arr{
    int max_1 , max_2;
}st[4 * N];

arr emp;

arr combine(arr a , arr b)
{
    if(a.max_1 == emp.max_1)
        return b;
    if(b.max_1 == emp.max_1)
        return a;

    arr c;
    int d[5];
    d[1] = a.max_1;
    d[2] = a.max_2;
    d[3] = b.max_1;
    d[4] = b.max_2;
    sort(d + 1 , d + 5 , greater < int > ());

    c.max_1 = d[1];
    c.max_2 = d[2];
    return c;
}

void build(int id , int l , int r)
{
    if(l == r)
    {
        st[id].max_1 = a[l];
        st[id].max_2 = -1e18;
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2 , l , mid);
    build(id * 2 + 1 , mid + 1 , r);
    st[id] = combine(st[id * 2] , st[id * 2 + 1]);
}

void update(int id , int l , int r , int pos , int val)
{
    if(l > pos || r < pos)
        return;
    if(l == r)
    {
        st[id].max_1 = val;
        st[id].max_2 = -1e18;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2 , l , mid , pos , val);
    update(id * 2 + 1 , mid + 1 , r , pos , val);
    st[id] = combine(st[id * 2] , st[id * 2 + 1]);
}

//[2,9]
//= [2,5]
//  [6,7]
//  -> [2,7]
//  [8,9]
//  -> [2,9]
arr get(int id , int l , int r , int u , int v)
{
    if(l > v || r < u)
        return emp;

    if(l >= u && r <= v)
        return st[id];

    int mid = (l + r) / 2;
    return combine(get(id * 2 , l , mid , u , v),
                   get(id * 2 + 1 , mid + 1 , r , u , v));
}


//combine(rong, rong) -> rong
//combine(rong, x) -> x
//combine(x , rong) -> x
//combine(x , y)
//
//
//max(rong , x)
//    -1e18,x   -> x
//
//rong + x

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    emp.max_1 = -1e18;

    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
    build(1 , 1 , n);

    cin >> q;
    while(q--)
    {
        char f;
        cin >> f;
        if(f == 'U')
        {
            int pos , val;
            cin >> pos >> val;
            update(1 , 1 , n , pos , val);
        }
        else
        {
            int l , r;
            cin >> l >> r;

            arr ans = get(1 , 1 , n , l , r);
            cout << ans.max_1 + ans.max_2 << "\n";
        }
    }
}
