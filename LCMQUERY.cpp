#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1000000021;

struct Seg
{
    int n;
    vector<int> t;
    void build(vector<int> a)
    {
        n=(int)a.size()-1;
        t.assign(4*n+4,0);
        build(1,1,n,a);
    }
    void build(int id,int l,int r,vector<int> &a)
    {
        if(l==r)
        {
            t[id]=a[l];
            return;
        }
        int m=(l+r)/2;
        build(id*2,l,m,a);
        build(id*2+1,m+1,r,a);
        t[id]=max(t[id*2],t[id*2+1]);
    }
    int getmax(int id,int l,int r,int u,int v)
    {
        if(v<l||r<u) return 0;
        if(u<=l&&r<=v) return t[id];
        int m=(l+r)/2;
        return max(getmax(id*2,l,m,u,v),getmax(id*2+1,m+1,r,u,v));
    }
};

int mulmod(int x,int y)
{
    return (int)((__int128)x*(__int128)y%MOD);
}

int powmod(int a,int e)
{
    int r=1;
    while(e>0)
    {
        if(e&1) r=mulmod(r,a);
        a=mulmod(a,a);
        e>>=1;
    }
    return r;
}

const int MAXA=10000000;
int spf[MAXA+1];

void sieve(int lim)
{
    for(int i=2;i<=lim;i++)
    {
        if(spf[i]==0)
        {
            spf[i]=i;
            if((int)i*(int)i<=lim)
            {
                for(int j=i*i;j<=lim;j+=i)
                {
                    if(spf[j]==0) spf[j]=i;
                }
            }
        }
    }
    spf[1]=1;
}

vector<pair<int,int>> factorize(int x)
{
    vector<pair<int,int>> res;
    while(x>1)
    {
        int p=spf[x];
        int c=0;
        while(x%p==0)
        {
            x/=p;
            c++;
        }
        res.push_back({p,c});
    }
    return res;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("LCMQUERY.INP","r",stdin);
    freopen("LCMQUERY.OUT","w",stdout);
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1);
    int maxA=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>maxA) maxA=a[i];
    }
    sieve(maxA);
    vector<int> primes;
    vector<vector<pair<int,int>>> fact(n+1);
    for(int i=1;i<=n;i++)
    {
        fact[i]=factorize(a[i]);
        for(int j=0;j<(int)fact[i].size();j++)
        {
            int p=fact[i][j].first;
            bool found=false;
            for(int k=0;k<(int)primes.size();k++)
            {
                if(primes[k]==p)
                {
                    found=true;
                    break;
                }
            }
            if(!found) primes.push_back(p);
        }
    }
    int P=(int)primes.size();
    vector<Seg> segs(P);
    for(int idx=0;idx<P;idx++)
    {
        int p=primes[idx];
        vector<int> exp(n+1,0);
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<(int)fact[i].size();j++)
            {
                if(fact[i][j].first==p)
                {
                    exp[i]=fact[i][j].second;
                    break;
                }
            }
        }
        segs[idx].build(exp);
    }
    for(int qi=1;qi<=q;qi++)
    {
        int l,r;
        cin>>l>>r;
        int ans=1;
        for(int idx=0;idx<P;idx++)
        {
            int exp=segs[idx].getmax(1,1,n,l,r);
            if(exp>0)
            {
                ans=mulmod(ans,powmod(primes[idx]%MOD,exp));
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
