#include<bits/stdc++.h>

using namespace std;

int memo[105][105],v[105][105],visited[105][105];
int row[4] = {+1,0,-1,0};
int col[4] = {0,+1,0,-1};
int dfs(int r, int c, int R, int C){
    if(r < 0 || r >= R || c < 0 || c >= C) return 0;
    if(memo[r][c]) return memo[r][c];
    if(visited[r][c]) return 0;
    visited[r][c] = 1;
    int temp = 1;
    for(int i = 0; i < 4; i++)
        if(v[r][c] > v[r+row[i]][c+col[i]])temp = max(temp,1+dfs(r+row[i],c+col[i],R,C));
    return memo[r][c] = temp;
}

int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int test;
    cin >> test;
    while(test--){
        string name; int r,c;
        cin >> name >> r >> c;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> v[i][j];
            }
        }
        memset(memo,0,sizeof memo);
        int ans = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                memset(visited,0,sizeof visited);
                ans = max(ans,dfs(i,j,r,c));
            }
        }
        cout << name << ": " << ans << endl;
    }
    return 0;
}
