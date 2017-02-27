#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<int>> v;

int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int test;
    cin >> test;
    for(int t = 1; t <= test; t++){
        v.clear();
        cin >> n;
        v.resize(n,vector<int>(n,INT_MAX));
        for(int i = 0; i < n; i++) v[i][i] = 0;
        cin >> m;
        while(m--){
            int u,_v;
            cin >> u >> _v;
            v[u][_v] = 1;
            v[_v][u] = 1;
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(v[i][k] == INT_MAX || v[k][j] == INT_MAX) continue;
                    v[i][j] = min(v[i][j],v[i][k]+v[k][j]);
                }
            }
        }
        int s,d,ans = -1;
        cin >> s >> d;
        for(int i = 0; i < n; i++){
            if(v[s][i] == INT_MAX || v[d][i] == INT_MAX) continue;
            ans = max(ans,v[s][i]+v[d][i]);
        }
        cout << "Case " << t << ": " << ans << endl;
    }
    return 0;
}
