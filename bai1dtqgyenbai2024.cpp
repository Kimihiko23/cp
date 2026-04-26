#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7+23;
int prent[N]={0},prehs[N]={0};

vector<int> ans1;
map<int, int> cnt;
int ans=0;
bool dd[N];
void sang()
{
    for(int i=2; i<N; i++)
    {
        if (dd[i])
        {
            for (int j=i*i; j<N; j+=i)
            {
                dd[j]=false;
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
    const int INF = LLONG_MAX;
    cnt[0]=0;
    int tam;
    for(int i=0;i<N;i++)
    {
        dd[i]=true;
    }
    dd[1]=false;
    dd[0]=false;
    sang();
    int n,k;
    cin >> n >> k;
    int ans2=0;
    int tam1,tam2;
    prent[0]=0;
    prehs[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin >> tam;
        prent[i]=prent[i-1];
        prehs[i]=prehs[i-1];
        if (dd[tam])
        {
            prent[i]++;
        }
        else
        {
            prehs[i]++;
        }
        
        tam1=prent[i] - prehs[i]*k;
        
        if(cnt.find(tam1) == cnt.end()) 
        {  
          cnt[tam1] = INF;
        }
        if (cnt[tam1]!=INF)
        {
            if (i-cnt[tam1] > ans)
            {
                ans1.clear();
                ans = i - cnt[tam1];
                ans1.push_back(cnt[tam1]);
                
            }
            else {
            if (i-cnt[tam1] == ans)
            {
                ans1.push_back(cnt[tam1]);
            }
            }
        }
        else
        {
            cnt[tam1] = min(cnt[tam1], i);
        }
    }
    cout << ans<< "\n";
    sort(ans1.begin(), ans1.end());
    reverse(ans1.begin(), ans1.end());
    while (!ans1.empty())
    {
        cout << ans1.back()+1 << " ";
        ans1.pop_back();
    }
    

}
