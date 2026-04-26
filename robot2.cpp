#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n, m, P, Q, T;
char grid[55][55];
int dist[55][55][8];
int key_pos[3][2];
int key_count;

struct State {
    int x, y, mask, cost;
    bool operator>(const State& other) const {
        return cost > other.cost;
    }
};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
}

int bfs(int sx, int sy) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < 8; k++)
                dist[i][j][k] = INF;
    
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({sx, sy, 0, 0});
    dist[sx][sy][0] = 0;
    
    while(!pq.empty()) {
        State cur = pq.top();
        pq.pop();
        
        if(cur.mask == 7 && (cur.x == 0 || cur.x == n-1 || cur.y == 0 || cur.y == m-1))
            return cur.cost + T;
        
        if(cur.cost != dist[cur.x][cur.y][cur.mask])
            continue;
        
        for(int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            
            if(!isValid(nx, ny)) continue;
            
            int new_mask = cur.mask;
            int new_cost = cur.cost + 1;
            
            if(grid[nx][ny] == 'K') {
                for(int k = 0; k < 3; k++) {
                    if(nx == key_pos[k][0] && ny == key_pos[k][1]) {
                        new_mask |= (1 << k);
                        break;
                    }
                }
                new_cost += P;
            }
            else if(grid[nx][ny] == 'V') {
                new_cost += Q;
            }
            
            if(new_cost < dist[nx][ny][new_mask]) {
                dist[nx][ny][new_mask] = new_cost;
                pq.push({nx, ny, new_mask, new_cost});
            }
        }
    }
    return INF;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //freopen("ROBOT2.INP", "r", stdin);
    //freopen("ROBOT2.OUT", "w", stdout);
    
    cin >> n >> m >> P >> Q >> T;
    
    int start_x, start_y;
    key_count = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'X') {
                start_x = i;
                start_y = j;
            }
            else if(grid[i][j] == 'K') {
                key_pos[key_count][0] = i;
                key_pos[key_count][1] = j;
                key_count++;
            }
        }
    }
    
    int result = bfs(start_x, start_y);
    cout << result << endl;
    
    return 0;
}