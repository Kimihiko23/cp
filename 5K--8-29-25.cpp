#include <bits/stdc++.h>
#define int long long
using namespace std;

struct P{int r,c;};
int n,m;
vector<char> t;
vector<int> rf;
vector<P> s;
vector<vector<bool>> u;
int d2(const P&a,const P&b)
{
    int dr=a.r-b.r,dc=a.c-b.c;
    return dr*dr+dc*dc;
}
void read()
{
    cin>>n>>m;
    t.resize(m+1);
    rf.resize(m+1);
    s.resize(m+1);
    for(int i=1;i<=m;i++){cin>>t[i];
    if(t[i]=='R')cin>>rf[i];}
    u.assign(n+1,vector<bool>(3));
}
void solve()
{
    for(int k=1;k<=m;k++){
        if(t[k]=='V'){
            P ch;
            if(k==1)ch={1,1};
            else{
                int best=-1;
                for(int r=1;r<=n;r++)for(int c=1;c<=2;c++)if(!u[r][c]){
                    P cur={r,c};int mn=LLONG_MAX;
                    for(int j=1;j<k;j++)if(t[j]=='V'&&u[s[j].r][s[j].c])mn=min(mn,d2(cur,s[j]));
                    if(mn>best||(mn==best&&(cur.r<ch.r||(cur.r==ch.r&&cur.c<ch.c)))){best=mn;ch=cur;}
                }
            }
            u[ch.r][ch.c]=1;s[k]=ch;cout<<ch.r<<" "<<ch.c<<"\n";
        }else{
            P p=s[rf[k]];u[p.r][p.c]=0;
        }
    }
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("5K.INP","r",stdin);
    freopen("5K.OUT","w",stdout);
    read();solve();
}
