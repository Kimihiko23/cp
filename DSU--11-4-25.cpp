    #include <bits/stdc++.h>
    #define int long long
    #define pb push_back
    #define fi first
    #define se second
    using namespace std;
    const int N =1e5+23;
    int n,m;
    int par[N];
    int sz[N];
    int findpar(int v)
    {
        if (v==par[v])
        {
            return v;
        }
        else
        {
            par[v]=findpar(par[v]);
        }
        return par[v];
    }
    void joinset(int a,int b)
    {
        a=findpar(a);
        b=findpar(b);
        if (a!=b)
        {
            if (sz[a]<sz[b])
            {
                swap(a,b);
            }
            sz[a]+=sz[b];
            par[b]=a;
        }
    }
    void read()
    {
        cin >> n >> m;
    }
    void solve()
    {
        for(int i=1;i<=n;i++)
        {
            par[i]=i;
            sz[i]=1;
        }
        while(m--)
        {
            int u,v;
            char s;
            cin >> s;
            if (s=='+')
            {
                cin >> u >>v;
                joinset(u,v);

            }
            else
            {
                cin >> u >> v;
                if(findpar(u)==findpar(v))
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
            }
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
        solve();
    
        
    }
