#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> v;
vector<bool> visited;
vector<int> degree;
int n,m;
int cnt;
void dfs(int p){
    visited[p] = true;
    cnt++;
    for(int i = 0; i < v[p].size(); i++){
        int c = v[p][i];
        if(visited[c]) continue;
        dfs(c);
    }
}

int main(){
    while(cin >> n >> m){
        v.clear();
        v.resize(n);
        degree.clear();
        degree.resize(n);
        int start = -1;
        while(m--){
            int x,y;
            cin >> x >> y;
            if(start == -1) start = x;
            v[x].push_back(y);
            v[y].push_back(x);
            degree[x]++; degree[y]++;
        }
        if(start == -1) {cout << "Not Possible\n";continue;}
        visited.clear();
        visited.resize(n);
        cnt=0;
        dfs(start);
        bool odd = false;
        int node = 0;
        for(int i = 0; i < n && !odd; i++){
            if(degree[i]&1) odd = true;
            if(degree[i]) node++;
        }
        if(!odd && node == cnt) cout << "Possible\n";
        else cout << "Not Possible\n";
    }
    return 0;
}
