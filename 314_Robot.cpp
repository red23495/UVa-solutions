#include<bits/stdc++.h>

using namespace std;
using ii = pair<int,int>;

int r,c;
vector<vector<int>> v;
int x_off[4] = {-1,0,+1,0};
int y_off[4] = {0,+1,0,-1};
int turn_left(int i){
    if(!i) return 3; return i-1;
}

int turn_right(int i){
    if(i == 3) return 0; return i+1;
}

bool is_valid(int i, int j){
    if(i <= 0 || j <= 0 || i >= r || j >= c) return false;
    if(v[i-1][j] == -1) return false;
    if(v[i][j-1] == -1) return false;
    if(v[i-1][j-1] == -1) return false;
    if(v[i][j] == -1) return false;
    return true;
}

int main(){
    while(cin >> r >> c && r){
        v.clear();
        v.resize(r,vector<int>(c));
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> v[i][j];
                if(v[i][j]) v[i][j] = -1;
            }
        }
        int bx,by,ex,ey,dir; string s;
        cin >> bx >> by >> ex >> ey >> s;
        if(s[0] == 'n') dir = 0;
        else if(s[0] == 'e') dir = 1;
        else if(s[0] == 's') dir = 2;
        else if(s[0] == 'w') dir = 3;
        int visited[51][51][4];
        memset(visited,0,sizeof visited);
        queue<pair<ii,int>> q;
        q.push({{bx,by},dir});
        visited[bx][by][dir] = 1;
        v[bx][by] = 1;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int x = p.first.first, y = p.first.second, d = p.second;
            if(x == ex && y == ey) break;
            for(int i = 1; i < 4; i++){
                int tx = x+x_off[d]*i, ty = y+y_off[d]*i;
                if(!is_valid(tx,ty)) break;
                else if(!visited[tx][ty][d]){
                    visited[tx][ty][d] = visited[x][y][d]+1;
                    if(v[tx][ty])v[tx][ty] = min(visited[tx][ty][d],v[tx][ty]);
                    else v[tx][ty] = visited[tx][ty][d];
                    q.push({{tx,ty},d});
                }
            }
            int L = turn_left(d), R = turn_right(d);
            if(!visited[x][y][L]){
                visited[x][y][L] = visited[x][y][d]+1;
                q.push({{x,y},L});
            }
            if(!visited[x][y][R]){
                visited[x][y][R] = visited[x][y][d]+1;
                q.push({{x,y},R});
            }
        }
        if(v[ex][ey] > 0)cout << v[ex][ey]-1 << endl;
        else cout << -1 << endl;
    }
    return 0;
}
