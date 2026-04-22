#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
char a[305][305];
bool vis[305][305];
int cnt;

map<char,int> tile=
{
    {'I',0},{'J',1},{'K',2},{'L',3},
    {'E',4},{'F',5},{'G',6},{'H',7},
    {'A',8},{'B',9},{'C',10},{'D',11}
};

int pattern[12][4]=
{
    {0,0,1,1},
    {1,1,0,0},
    {1,1,1,0},
    {1,0,1,1},
    {1,0,0,1},
    {0,1,1,0},
    {1,0,1,0},
    {0,1,0,1},
    {1,0,0,0},
    {0,1,0,0},
    {0,0,1,0},
    {0,0,0,1}
};

void dfs(int i,int j)
{
    if(i<0||i>=n||j<0||j>=m||vis[i][j])return;
    vis[i][j]=1;
    
    int t=tile[a[i][j]];
    if(pattern[t][0])dfs(i-1,j);
    if(pattern[t][1])dfs(i,j+1);
    if(pattern[t][2])dfs(i+1,j);
    if(pattern[t][3])dfs(i,j-1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    freopen("GHEPTRANH.INP","r",stdin);
    freopen("GHEPTRANH.OUT","w",stdout);
    
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j];
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(!vis[i][j]){
                dfs(i,j);
                cnt++;
            }
    
    cout<<cnt;
}