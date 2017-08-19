#include<bits/stdc++.h>

#define IOBOOST cin.sync_with_stdio(false);cout.sync_with_stdio(false);

using namespace std;
using vii = vector<vector<int>>;
using vi = vector<int>;

#define MAX_COST 10000000
#define ENTRY(i) (i)
#define EXIT(i) (i+50)
int constexpr max_node = 110;
int constexpr source = 1;
int sink;
vii v;
int weight[max_node][max_node];

int main(){
    IOBOOST
    int m,w;
    while(cin >> m >> w && m ){
        memset(weight,0,sizeof weight);
        v.clear();
        v.resize(max_node);
        sink = m;
        v[ENTRY(source)].push_back(EXIT(source));
        v[EXIT(source)].push_back(ENTRY(source));
        weight[ENTRY(source)][EXIT(source)] = MAX_COST;
        weight[EXIT(source)][ENTRY(source)] = MAX_COST;
        v[ENTRY(sink)].push_back(EXIT(sink));
        v[EXIT(sink)].push_back(ENTRY(sink));
        weight[ENTRY(sink)][EXIT(sink)] = MAX_COST;
        weight[EXIT(sink)][ENTRY(sink)] = MAX_COST;
        for(int i = 0; i < m-2; i++){
            int id,val;
            cin >> id >> val;
            v[ENTRY(id)].push_back(EXIT(id));
            v[EXIT(id)].push_back(ENTRY(id));
            weight[ENTRY(id)][EXIT(id)] = val;
            weight[EXIT(id)][ENTRY(id)] = val;
        }
        for(int i = 0; i < w; i++){
            int a,b,c;
            cin >> a >> b >> c;
            if(a > b){
                int t = a;
                a = b;
                b = t;
            }
            v[EXIT(a)].push_back(ENTRY(b));
            v[ENTRY(b)].push_back(EXIT(a));
            weight[EXIT(a)][ENTRY(b)] = c;
            v[EXIT(b)].push_back(ENTRY(a));
            v[ENTRY(a)].push_back(EXIT(b));
            weight[EXIT(b)][ENTRY(a)] = c;
        }
        int maxFlow = 0;
        while(true){
            queue<int> q;
            q.push(ENTRY(source));
            vi parent(max_node),visited(max_node);
            visited[ENTRY(source)] = 1;
            bool found = false;
            while(!found && !q.empty()){
                int p = q.front();
                q.pop();
                for(int i = 0; i < v[p].size(); i++){
                    int child = v[p][i];
                    if(weight[p][child] <= 0 || visited[child]) continue;
                    //cout << p << ' ' << child<< ' '<<weight[p][child] << endl;
                    visited[child] = 1;
                    parent[child] = p;
                    q.push(child);
                    if(child == EXIT(sink)) {found = true;break;}
                }
            }
            if(!found) break;
            int m = INT_MAX;
            int e = EXIT(sink);
            while(e != ENTRY(source)){
                m = min(weight[parent[e]][e],m);
                e = parent[e];
            }
            //cout << m << endl;
            maxFlow += m;
            e = EXIT(sink);
            while(e != ENTRY(source)){
                weight[parent[e]][e] -= m;
                weight[e][parent[e]] += m;
                e = parent[e];
            }
        }
        cout << maxFlow << endl;
    }
    return 0;
}
