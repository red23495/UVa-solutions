#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n,grid[10][10],start_row,start_col,last_food;
struct record{int row,col,cur;};
ll dist[10][10][27],path[10][10][27][1000];
bool visited[10][10][27];
constexpr int mod = 20437;

// find the shortest path with bfs
// find the number of paths with dp

ll path_count(int r, int c, int cur, int len){
    //cout << r << ' ' << c << ' ' << cur << ' ' << len << endl;
    if(last_food == 1) return 1;
    if(r < 0 || c < 0 || r >= n || c >= n) return 0;
    if(len < 0) return 0;
    if(path[r][c][cur][len] != -1) return path[r][c][cur][len];
    if(grid[r][c] == -1 || grid[r][c] > cur+1) return path[r][c][cur][len] = 0;
    if(grid[r][c] == cur+1 && grid[r][c] == last_food) return path[r][c][cur][len] = 1;
    int next_cur = cur;
    if(grid[r][c] == cur+1) next_cur++;
    int nav_row[4] = {-1,1,0,0};
    int nav_col[4] = {0,0,-1,1};
    path[r][c][cur][len] = 0;
    for(int i = 0; i < 4; i++){
        ll temp = path_count(r+nav_row[i],c+nav_col[i],next_cur,len-1);
        if(temp != -1) path[r][c][cur][len] += temp;
    }
    return path[r][c][cur][len] %= mod;
}

int main(){
    int test = 1;
    while(cin >> n && n){
        last_food = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                char c;
                cin >> c;
                switch(c){
                case '#':
                    grid[i][j] = -1;
                    break;
                case '.':
                    grid[i][j] = 0;
                    break;
                default:
                    grid[i][j] = c-'A'+1;
                    last_food = max(last_food,c-'A'+1);
                    if(c == 'A') start_row = i, start_col = j;
                    break;
                }
            }
        }
        queue<record> q;
        int ans = INT_MAX;
        bool found = false;
        q.push({start_row,start_col,1});
        memset(dist,0,sizeof dist);
        memset(visited,0,sizeof visited);
        visited[start_row][start_col][1] = true;
        int nav_row[4] = {-1,1,0,0};
        int nav_col[4] = {0,0,-1,1};
        while(!q.empty() && !found){
            if(last_food == 1) {ans = 0;found = true; break;}
            record temp = q.front();
            q.pop();
            int r = temp.row, c = temp.col, cur = temp.cur;
            //cout << r << ' ' << c << ' ' << cur << endl;
            for(int i = 0; i < 4; i++){
                int n_r = r + nav_row[i], n_c = c + nav_col[i];
                if(n_r < 0 || n_c < 0 || n_r >= n || n_c >= n || grid[n_r][n_c] == -1) continue;
                int next_cur = cur;
                if(grid[n_r][n_c] > cur+1) continue;
                if(grid[n_r][n_c] == cur+1) next_cur++;
                if(dist[n_r][n_c][next_cur]) continue;
                visited[n_r][n_c][next_cur] = true;
                if(next_cur == last_food) {
                    ans = dist[r][c][cur]+1;
                    //cout << ans << endl;
                    found = true;
                    break;
                }
                dist[n_r][n_c][next_cur] = dist[r][c][cur]+1;
                q.push({n_r,n_c,next_cur});
            }
        }
        memset(path,-1,sizeof path);
        cout << "Case " << test++ << ": ";
        if(ans == INT_MAX) cout << "Impossible\n";
        else cout << ans << ' ' << path_count(start_row,start_col,1,ans) << endl;
    }
    return 0;
}
