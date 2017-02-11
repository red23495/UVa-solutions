#include<bits/stdc++.h>

using namespace std;

int m,n,r,c;
vector<vector<char>> v;
char land;
int fill(int i, int j){
    v[i][j] = '.';
    int c = 0;
    if(i > 0 && v[i-1][j] == land) c = c+1+fill(i-1,j);
    if(i < m-1 && v[i+1][j] == land) c = c+1+fill(i+1,j);
    if(j == 0 && v[i][n-1] == land) c = c+1+fill(i,n-1);
    else if(v[i][j-1] == land) c = c+1+fill(i,j-1);
    if(v[i][(j+1)%n] == land) c = c+1+fill(i,(j+1)%n);
    return c;
}

int main(){
    while(cin >> m >> n){
        v.clear();
        v.resize(m,vector<char>(n));
        for(auto& x: v){
            for(auto& y: x) cin >> y;
        }
        cin >> r >> c;
        land = v[r][c];
        fill(r,c);
        int ans = -1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(v[i][j] == land){
                    int p = fill(i,j);
                    if(p > ans) ans = p;
                }
            }
        }
        cout << ans+1 << endl;
    }
    return 0;
}
