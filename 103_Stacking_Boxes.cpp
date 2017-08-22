#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> box,v;
vector<int> w,visited;
vector<int> seq;

bool fits(vector<int> small, vector<int> large){
    for(int i = 0; i < small.size(); i++){
        if(small[i] >= large[i]) return false;
    }
    return true;
}

int dfs(int p){
    int c = v[p].size();
    if(visited[p]) return w[p];
    if(!c) return w[p] = 1;
    visited[p] = 1;
    for(int i = 0; i < c; i++){
        int child = v[p][i];
        w[p] = max(w[p],1+dfs(child));
    }
    return w[p];
}

void path_trace(int p){
    int c = v[p].size();
    seq.push_back(p);
    if(!c) return;
    int m = 0, cw = 0;
    for(int i = 0; i < c; i++) {
        if(w[v[p][i]] > cw){
            cw = w[v[p][i]];
            m = v[p][i];
        }
    }
    path_trace(m);
}

int main(){
    int n,dim;
    while(cin >> n >> dim){
        v.clear();
        v.resize(n);
        box.clear();
        box.resize(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < dim; j++){
                int x;
                cin >> x;
                box[i].push_back(x);
            }
        }
        for(int i = 0; i < n; i++){
            sort(box[i].begin(),box[i].end());
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(fits(box[i],box[j])) v[j].push_back(i);
            }
        }
        int m = 0;
        for(int i = 0; i < n; i++){
            w.clear();w.resize(n);
            visited.clear();visited.resize(n);
            int t = dfs(i);
            if(t > m){
                m = t;
                seq.clear();
                path_trace(i);
            }
        }
        cout << m << endl;
        for(int i = 0; i < m; i++) {
            if(i) cout << ' '; cout << seq[m-i-1]+1;
        }
        cout << endl;
    }
    return 0;
}
