#include<bits/stdc++.h>

using namespace std;

#define START 10
#define END 11

vector<vector<char>> v;
vector<vector<int>> weight;

int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    while(!cin.eof()){
        int total = 0;
        string s;
        v.clear();
        v.resize(128);
        weight.clear();
        weight.resize(128,vector<int>(128));
        while(getline(cin,s) && s.length()){
            stringstream ss(s);
            char c,d;int n;
            ss >> c >> n;
            v[START].push_back(c);
            v[c].push_back(START);
            weight[START][c] = n;
            total += n;
            while(ss >> d && d != ';'){
                v[c].push_back(d);
                v[d].push_back(c);
                weight[c][d] = 1;
            }
        }
        for(int i = '0'; i <= '9'; i++) {v[i].push_back(END);weight[i][END] = 1;}
        int maxFlow = 0;
        while(true){
            queue<int> q;
            q.push(START);
            vector<int> parent(128),visited(128,0);
            bool found = false;
            visited[START] = 1;
            while(!q.empty() && !found){
                int p = q.front();
                //cout << (char)p << endl;
                q.pop();
                for(int i = 0; i < v[p].size(); i++){
                    int child = v[p][i];
                    if(weight[p][child] <= 0 || visited[child] == 1) continue;
                    //cout << (char)p << ' ' << (char)child << endl;
                    parent[child] = p;
                    visited[child] = 1;
                    if(child == END) {found = true; break;}
                    q.push(child);
                }
            }
            if(!found) break;
            int m = INT_MAX;
            int e = END;
            while(e != START){
                m = min(m,weight[parent[e]][e]);
                e = parent[e];
                //cout << (char)e << endl;
            }
            maxFlow += m;
            e = END;
            while(e != START){
                weight[parent[e]][e] -= m;
                weight[e][parent[e]] += m;
                e = parent[e];
            }
        }
        //cout << maxFlow << endl;
        if(maxFlow != total) cout << "!\n";
        else{
            for(int i = '0'; i <= '9'; i++){
                char c = '_';
                for(int j = 'A'; j <= 'Z' && c == '_'; j++){
                    if(weight[i][j]) c = j;
                }
                cout << c ;
            }
            cout << endl;
        }
    }
    return 0;
}
