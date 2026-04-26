    #include <bits/stdc++.h>
    #define int long long
    #define pb push_back
    #define fi first
    #define se second
    using namespace std;
    const int N =2000;
    int a[N][N];
    int dis[N][N];
    int n,m;
    bool check(int x,int y)
    {
        if (x>=1 && x<=n && y>=1 && y<=m)
            return true;
        return false;
    }
    void bfs()
    {
        queue<pair<int,pair<int,int>>> tt;
        tt.push({1,{1,0}});
        dis[1][1]=0;
        while(!tt.empty())
        {
            auto u=tt.front();
            tt.pop();
            if (check(u.fi,u.se.fi+a[u.fi][u.se.fi]) && 
                dis[u.fi][u.se.fi+a[u.fi][u.se.fi]]>dis[u.fi][u.se.fi]+1 &&
                u.se.se!=3)
            {
                dis[u.fi][u.se.fi+a[u.fi][u.se.fi]]=dis[u.fi][u.se.fi]+1;
                tt.push({u.fi,{u.se.fi+a[u.fi][u.se.fi],3}});
            }
            if (check(u.fi,u.se.fi-a[u.fi][u.se.fi]) && 
                dis[u.fi][u.se.fi-a[u.fi][u.se.fi]]>dis[u.fi][u.se.fi]+1 &&
                u.se.se!=7)
            {
                dis[u.fi][u.se.fi-a[u.fi][u.se.fi]]=dis[u.fi][u.se.fi]+1;
                tt.push({u.fi,{u.se.fi-a[u.fi][u.se.fi],7}});
            }
            if (check(u.fi-a[u.fi][u.se.fi],u.se.fi) && 
                dis[u.fi-a[u.fi][u.se.fi]][u.se.fi]>dis[u.fi][u.se.fi]+1 &&
                u.se.se!=1)
            {
                dis[u.fi-a[u.fi][u.se.fi]][u.se.fi]=dis[u.fi][u.se.fi]+1;
                tt.push({u.fi-a[u.fi][u.se.fi],{u.se.fi,1}});
            }
            if (check(u.fi+a[u.fi][u.se.fi],u.se.fi) && 
                dis[u.fi+a[u.fi][u.se.fi]][u.se.fi]>dis[u.fi][u.se.fi]+1 &&
                u.se.se!=5)
            {
                dis[u.fi+a[u.fi][u.se.fi]][u.se.fi]=dis[u.fi][u.se.fi]+1;
                tt.push({u.fi+a[u.fi][u.se.fi],{u.se.fi,5}});
            }
            
            
            //cheo
                //cheo xuong phai
            if (check(u.fi+a[u.fi][u.se.fi],u.se.fi+a[u.fi][u.se.fi]) && 
                dis[u.fi+a[u.fi][u.se.fi]][u.se.fi+a[u.fi][u.se.fi]]>dis[u.fi][u.se.fi]+1 &&
                u.se.se!=4)
            {
                dis[u.fi+a[u.fi][u.se.fi]][u.se.fi+a[u.fi][u.se.fi]]=dis[u.fi][u.se.fi]+1;
                tt.push({u.fi+a[u.fi][u.se.fi],{u.se.fi+a[u.fi][u.se.fi],4}});
            }
                //cheo len trai
            if (check(u.fi-a[u.fi][u.se.fi],u.se.fi-a[u.fi][u.se.fi]) && 
                dis[u.fi-a[u.fi][u.se.fi]][u.se.fi-a[u.fi][u.se.fi]]>dis[u.fi][u.se.fi]+1 &&
                u.se.se!=8)
            {
                dis[u.fi-a[u.fi][u.se.fi]][u.se.fi-a[u.fi][u.se.fi]]=dis[u.fi][u.se.fi]+1;
                tt.push({u.fi-a[u.fi][u.se.fi],{u.se.fi-a[u.fi][u.se.fi],8}});
            }
                //cheo len phai
            if (check(u.fi-a[u.fi][u.se.fi],u.se.fi+a[u.fi][u.se.fi]) && 
                dis[u.fi-a[u.fi][u.se.fi]][u.se.fi+a[u.fi][u.se.fi]]>dis[u.fi][u.se.fi]+1 &&
                u.se.se!=2)
            {
                dis[u.fi-a[u.fi][u.se.fi]][u.se.fi+a[u.fi][u.se.fi]]=dis[u.fi][u.se.fi]+1;
                tt.push({u.fi-a[u.fi][u.se.fi],{u.se.fi+a[u.fi][u.se.fi],2}});
            }
                //cheo xuong trai
            if (check(u.fi+a[u.fi][u.se.fi],u.se.fi-a[u.fi][u.se.fi]) && 
                dis[u.fi+a[u.fi][u.se.fi]][u.se.fi-a[u.fi][u.se.fi]]>dis[u.fi][u.se.fi]+1 &&
                u.se.se!=6)
            {
                dis[u.fi+a[u.fi][u.se.fi]][u.se.fi-a[u.fi][u.se.fi]]=dis[u.fi][u.se.fi]+1;
                tt.push({u.fi+a[u.fi][u.se.fi],{u.se.fi-a[u.fi][u.se.fi],6}});
            }
            

        }

    }
    void read()
    {
        cin >> n >> m;
        swap(n,m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin >> a[i][j];
                dis[i][j]=1e18;
            }
        }
    }
    void solve()
    {
        bfs();
        /*for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout << dis[i][j] << " ";
            }
            cout << "\n";
        }*/
        if (dis[n][m]>=1e17)
        {
            cout << -1;
        }
        else
        cout << dis[n][m];
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
