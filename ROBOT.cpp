#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N=1e3+5;
const int POS=1e2+5;
vector<pair<int,int>> a[N];
int cnt[N], d[POS][N], n, m, p, start[POS];
void dijsktra(int source, int pos)
{
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,source});
	d[pos][source]=0;
	while (!pq.empty())
	{
		int u = pq.top().second;
		int wu = pq.top().first;
		pq.pop();
		if (d[pos][u]!=wu)
		{
			continue;
		}
		for (int i=0;i<a[u].size();i++)
		{
			int v=a[u][i].first;
			int wv=a[u][i].second;
			if (wu+wv<d[pos][v])
			{
				d[pos][v]=wu+wv;
				pq.push({d[pos][v], v});
			}
		}
		cnt[u]++;
	}
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	freopen("ROBOT.INP","r",stdin);
	freopen("ROBOT.OUT","w",stdout);
	cin >> p >> n >> m;
	for (int i=1;i<=p;i++)
	{
		cin >> start[i];
	}
	for (int i=1;i<=m;i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].push_back({v,1});
		a[v].push_back({u,1});
	}
	for (int i=1;i<=p;i++)
	{
		for (int j=1;j<=n;j++)
		{
			d[i][j]=1e18;
		}
	}
	for (int i=1;i<=p;i++)
	{
		dijsktra(start[i], i);
	}
	int ans=1e18;
	for (int i=1;i<=n;i++)
	{
		int sum=0;
		for (int j=1;j<=p;j++)
		{
			sum+=d[j][i];
		}
		ans=min(ans,sum);
	}
	cout << ans;
}