#include<bits/stdc++.h>

using namespace std;

int n,l;
vector<vector<int>> g;
vector<char> color;
vector<bool> visited;
bool bicolor(int in,char col){
    queue<int> l;
    color[in] = col;
    visited[in] = true;
    char opp = (col == 'w')?'b':'w';
    bool ans = true;
    for(int i = 0; i < g[in].size() && ans; i++){
        if(color[g[in][i]] == col) ans = false;
        else if(!visited[g[in][i]]) {
            l.push(g[in][i]);
        }
    }
    while(!l.empty() && ans){
        int t = l.front();
        l.pop();
        ans = bicolor(t,opp);
    }
    return ans;
}

int main(){
    while(cin >> n && n){
        g.clear();
        g.resize(n);
        cin >> l;
        color.clear();
        color.resize(n,'n');
        visited.clear();
        visited.resize(n,false);
        while(l--){
            int n1,n2;
            cin >> n1 >> n2;
            g[n1].push_back(n2);
            g[n2].push_back(n1);
        }
        if(bicolor(0,'w')) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";
    }
    return 0;
}
