void giai()
{
    int n;
    cin>>n;
    vector<ll> pf(n+1,0);
    for (int i=1;i<=n;i++)
    {
        ll ai;
        cin>>ai;
        pf[i] = pf[i-1] + ai;
    }
    ll x;
    cin>>x;
    ll dan = x / pf[n] * n;
    x%= pf[n];
    ll vt = upper_bound(pf.begin()+1,pf.end(),x) - pf.begin();
    dan+=vt;
    cout<<dan;
}