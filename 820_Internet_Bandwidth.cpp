#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> v,w;
int n,s,t,c;

int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int test = 1;
    while(cin >> n && n){
        v.clear();
        v.resize(n);
        w.clear();
        w.resize(n,vector<int>(n));
        cin >> s >> t >> c;
        s--;t--;
        while(c--){
            int x,y,z;
            cin >> x >> y >> z;
            x--;y--;
            v[x].push_back(y);
            v[y].push_back(x);
            w[x][y] += z;
            w[y][x] += z;
        }
        int maxFlow = 0;
        while(true){
            queue<int> q;
            q.push(s);
            vector<int> parent(n),visited(n);
            visited[s] = 1;
            bool found = false;
            while(!found && !q.empty()){
                int p = q.front();
                q.pop();
                for(int i = 0; i < v[p].size(); i++){
                    int child = v[p][i];
                    if(w[p][child] <= 0 || visited[child]) continue;
                    visited[child] = 1;
                    parent[child] = p;
                    q.push(child);
                    if(child == t){found = true;break;}
                }
            }
            if(!found) break;
            int m = INT_MAX;
            int e = t;
            while(e != s){
                    //cout << e << ' ';
                m = min(m,w[parent[e]][e]);
                e = parent[e];
            }
            //cout << endl;
            maxFlow += m;
            e = t;
            while(e != s){
                w[parent[e]][e] -= m;
                w[e][parent[e]] += m;
                e = parent[e];
            }
            //cout << "done\n";
        }
        cout << "Network " << test++ << endl;
        cout << "The bandwidth is " << maxFlow << ".\n\n";
    }
    return 0;
}
