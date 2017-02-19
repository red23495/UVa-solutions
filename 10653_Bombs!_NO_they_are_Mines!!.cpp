#include<bits/stdc++.h>

using namespace std;

int r,c;
vector<vector<int>> v;

int main(){
    while(cin >> r >> c && r){
        v.clear();
        v.resize(r,vector<int>(c));
        int n;
        cin >> n;
        while(n--){
            int x,y,z;
            cin >> x >> y;
            while(y--){
                cin >> z;
                v[x][z] = -1;
            }
        }
        int startx,endx,starty,endy;
        cin >> startx >> starty >> endx >> endy;
        v[startx][starty] = 1;
        queue<pair<int,int>> q;
        q.push({startx,starty});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int i = p.first, j = p.second;
            if(i == endx && j == endy) break;
            if(i > 0 && !v[i-1][j]){
                v[i-1][j] = v[i][j]+1;
                q.push({i-1,j});
            }
            if(i < r-1 && !v[i+1][j]){
                v[i+1][j] = v[i][j]+1;
                q.push({i+1,j});
            }
            if(j > 0 && !v[i][j-1]){
                v[i][j-1] = v[i][j]+1;
                q.push({i,j-1});
            }
            if(j < c-1 && !v[i][j+1]){
                v[i][j+1] = v[i][j]+1;
                q.push({i,j+1});
            }
        }
        cout << v[endx][endy]-1 << endl;
    }
    return 0;
}
