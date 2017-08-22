#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> v;
vector<int> w,visited;

void dfs(int p){
    //cout << "p " << p << endl;
    int c = v[p].size();
    if(!c) return;
    for(int i = 0; i < c; i++){
        if(!visited[v[p][i]]){
            visited[v[p][i]] = 1;
            dfs(v[p][i]);
        }
        w[p] += w[v[p][i]];
        //cout << w[p] << endl;
    }
}

int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int n;
    bool start = true;
    while(cin >> n){
        if(!start) cout << '\n'; else start = false;
        v.clear();
        v.resize(n);
        w.clear();
        w.resize(n);
        visited.clear();
        visited.resize(n);
        for(int i = 0; i < n; i++){
            int e;
            cin >> e;
            if(!e) w[i] = 1;
            while(e--){
                int x;
                cin >> x;
                v[i].push_back(x);
            }
        }
        visited[0] = 1;
        dfs(0);
        //for(int i = 0; i < n; i++) cout << w[i] << ' '; cout << endl;
        cout << w[0] << "\n";
    }
    return 0;
}
