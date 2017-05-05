#include<bits/stdc++.h>

using namespace std;

int x,y,p;
vector<vector<int>> v;
vector<vector<int>> w;
vector<string> grid;
#define START 2001
#define END 2002
#define ENTRY(ARG) ARG
#define EXIT(ARG) 1000+ARG
int xv[4] = {+1,-1,0,0};
int yv[4] = {0,0,+1,-1};

int val(char c){
    switch(c){
    case '*':case '.':
        return 1;
    case '@':case'#':
        return INT_MAX;
    }
}

bool check(int i, int j){
    if(i < 0 || i >= x || j < 0 || j >= y) return false;
    return true;
}

void connect(int i, int j, int cv){
    int n = i*y+j;
    v[ENTRY(n)].push_back(EXIT(n));
    w[ENTRY(n)][EXIT(n)] = cv;
    v[EXIT(n)].push_back(ENTRY(n));
    w[EXIT(n)][ENTRY(n)] = 0;
    for(int a = 0; a < 4; a++){
        if(check(i+xv[a],j+yv[a])){
            int z = val(grid[i+xv[a]][j+yv[a]]);
            int nn = (i+xv[a])*y+j+yv[a];
            v[EXIT(n)].push_back(ENTRY(nn));
            w[EXIT(n)][ENTRY(nn)] = z;
            v[ENTRY(nn)].push_back(EXIT(n));
            w[ENTRY(nn)][EXIT(n)] = 0;
            //cout << i+xv[a] << ' ' << j+yv[a] << ' ' << n << ' ' << nn << endl;
        }
    }
}

int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    while(cin >> x >> y >> p){
        grid.clear();
        grid.resize(x);
        w.clear();
        w.resize(2010,vector<int>(2010));
        for(int i = 0; i < x; i++) cin >> grid[i];
        v.clear();
        v.resize(2010);
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                if(grid[i][j] != '~'){
                    int n = i*y+j;
                    if(grid[i][j] == '*') {v[START].push_back(n);w[START][n] = INT_MAX;}
                    if(grid[i][j] == '#') {v[EXIT(n)].push_back(END);w[EXIT(n)][END] = p;}
                    int cval = val(grid[i][j]);
                    connect(i,j,cval);
                }
            }
        }
        int maxFlow = 0;
        while(true){
            bool found = false;
            vector<int> parent(2010);
            vector<bool> visited(2010);
            queue<int> q;
            q.push(START);
            visited[START] = true;
            while(!q.empty() && !found){
                int pr = q.front();
                q.pop();
                for(int i = 0; i < v[pr].size() && !found; i++){
                    int child = v[pr][i];
                    if(visited[child] || w[pr][child] <= 0) continue;
                    parent[child] = pr;
                    visited[child] = true;
                    q.push(child);
                    if(child == END) found = true;
                }
            }
            if(!found) break;
            int flow = INT_MAX;
            int it = END;
            while(it != START){
                //cout << it << ' ';
                int pr = parent[it];
                flow = min(flow,w[pr][it]);
                it = pr;
            }
            //cout << endl;
            maxFlow += flow;
            it = END;
            while(it != START){
                int pr = parent[it];
                w[pr][it] -= flow;
                w[it][pr] += flow;
                it = pr;
            }
        }
        cout << maxFlow << endl;
    }
    return 0;
}
