#include<bits/stdc++.h>

using namespace std;

int main(){
    int test;
    cin >> test;
    for(int t = 1; t <= test; t++){
        int m,n;
        cin >> n >> m;
        vector<vector<int>> v(n+m,vector<int>(n+m,INT_MAX/2));
        for(int i = 0; i < m; i++){
            int x,y;
            cin >> x >> y;
            v[x][n+i] = 1;
            v[n+i][x] = 1;
            v[n+i][y] = 1;
            v[y][n+i] = 1;
        }
        for(int i = 0; i < n+m; i++) v[i][i] = 0;
        for(int k = 0; k < n+m; k++){
            for(int i = 0; i < n+m; i++){
                for(int j = 0; j < n+m; j++){
                    v[i][j] = min(v[i][j],v[i][k]+v[k][j]);
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < n+m; i++){
            int first = 0, second = 0;
            for(int j = 0; j < n; j++){
                if(v[i][j] >= first){
                    second = first;
                    first = v[i][j];
                }else if(v[i][j] > second){
                    second = v[i][j];
                }
            }
            ans = min(ans,(first+second));
        }
        cout << "Case #"<<t<<":\n" << ans/2 << "\n\n";
    }
    return 0;
}
