#include<bits/stdc++.h>

using namespace std;

int n,m,counter,turn,rnd;
vector<vector<int>> v,print;
vector<string> id2name;
map<string,int> name2id;
vector<int> cur,low;
vector<bool> visited;
stack<int> ans;

void scc(int p){
    low[p] = cur[p] = ++turn;
    visited[p] = true;
    ans.push(p);
    for(int i = 0; i < v[p].size(); i++){
        int child = v[p][i];
        if(!cur[child]) scc(child);
        if(visited[child])low[p] = min(low[p],low[child]);
    }
    if(cur[p] == low[p]){
        vector<int> t;
        while(1){
            int x = ans.top();
            ans.pop();
            visited[x] = false;
            t.push_back(x);
            if(x == p) break;
        }
        print.push_back(t);
    }
}

bool start;
int main(){
    while(cin >> n >> m && (n || m)){
        if(start) cout << '\n';
        else start = true;
        counter = 0;
        v.clear();
        v.resize(n);
        id2name.clear();
        id2name.resize(n);
        name2id.clear();
        while(m--){
            string x,y;
            cin >> x >> y;
            int a,b;
            if(!name2id.count(x)){
                name2id[x] = counter;
                id2name[counter] = x;
                a = counter++;
            }else{
                a = name2id[x];
            }
            if(!name2id.count(y)){
                name2id[y] = counter;
                id2name[counter] = y;
                b = counter++;
            }else{
                b = name2id[y];
            }
            v[a].push_back(b);
        }
        cur.clear();
        cur.resize(n);
        low.clear();
        low.resize(n);
        visited.clear();
        visited.resize(n);
        print.clear();
        turn = 0;
        for(int i = 0; i < n; i++){
            if(!cur[i]) scc(i);
        }
        cout << "Calling circles for data set "<<++rnd<<":\n";
        for(int i = 0; i < print.size(); i++){
            for(int j = 0; j < print[i].size(); j++){
                if(j) cout << ", ";
                cout << id2name[print[i][j]];
            }
            cout << endl;
        }
    }
    return 0;
}
