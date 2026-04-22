#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int N, M;
string a[MAXN];

// lưới chi tiết 2N x 2M
int grid[MAXN*2][MAXN*2];
bool vis[MAXN*2][MAXN*2];

// 4 hướng
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

// kiểm tra trong bảng
bool inside(int x,int y) {
    return (x>=0 && y>=0 && x<2*N && y<2*M);
}

// DFS
void dfs(int x,int y) {
    stack<pair<int,int>> st;
    st.push({x,y});
    vis[x][y] = true;
    while(!st.empty()){
        auto [u,v] = st.top(); st.pop();
        for(int k=0;k<4;k++){
            int nx=u+dx[k], ny=v+dy[k];
            if(inside(nx,ny) && !vis[nx][ny] && grid[nx][ny]==1){
                vis[nx][ny]=true;
                st.push({nx,ny});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> N >> M;
    for(int i=0;i<N;i++) cin >> a[i];

    // chuyển sang lưới 2N x 2M
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            char c=a[i][j];
            int x=i*2, y=j*2;
            if(c=='A'){
                grid[x][y]=1; // top-left
            }else if(c=='B'){
                grid[x+1][y+1]=1; // bottom-right
            }else if(c=='C'){
                grid[x][y+1]=1; // top-right
            }else if(c=='D'){
                grid[x+1][y]=1; // bottom-left
            }else if(c=='E'){
                grid[x][y]=grid[x][y+1]=1; // top row
            }else if(c=='F'){
                grid[x][y]=grid[x][y+1]=grid[x+1][y]=grid[x+1][y+1]=1;
            }
        }
    }

    int ans=0;
    for(int i=0;i<2*N;i++){
        for(int j=0;j<2*M;j++){
            if(grid[i][j]==1 && !vis[i][j]){
                ans++;
                dfs(i,j);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
