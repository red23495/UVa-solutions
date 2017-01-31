#include<bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> g;
bitset<101> visited;
void dfs(int in, vector<int>& reached){
    if(visited[in] == 1) return;
    visited[in] = 1;
    reached.push_back(in);
    for(int i = 0; i < g[in].size(); i++){
        if(!visited[g[in][i]]) dfs(g[in][i],reached);
    }
}
int main(){
    int test;
    cin >> test;
    for(int t = 1; t <= test; t++){
        cin >> n;
        g.clear();
        g.resize(n,vector<int>());
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int x; cin >> x;
                if(x) g[i].push_back(j);
            }
        }
        visited.reset();
        vector<int> reachable;
        dfs(0,reachable);
        vector<vector<char>> ans(n,vector<char>(n,'N'));
        for(int i = 0; i < reachable.size(); i++){
            int x = reachable[i];
            visited.reset();
            visited[x] = 1;
            vector<int> current;
            dfs(0,current);
            for(int a = 0; a < reachable.size(); a++){
                bool found = false;
                for(int b = 0; b < current.size() && !found; b++){
                    if(current[b] == reachable[a]) found = true;
                }
                if(!found) ans[x][reachable[a]] = 'Y';
            }
        }
        cout << "Case " << t << ":\n";
        string s = "+";
        for(int i = 0; i < 2*n-1; i++)
            s.push_back('-');
        s.push_back('+');
        cout << s << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << '|' << ans[i][j];
            }
            cout << "|\n" << s << endl;
        }
    }
    return 0;
}
