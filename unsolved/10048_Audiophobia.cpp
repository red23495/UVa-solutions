#include<bits/stdc++.h>

using namespace std;

int n,m,q;
vector<pair<pair<int,int>,int>> e;
vector<vector<pair<int,int>>> v;

class union_find{
    vector<int> p,rank;
public:
    union_find(int n){
        p.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++) p[i] = i;
    }
    int parent(int i){
        if(i == p[i]) return i;
        return p[i] = parent(p[i]);
    }
    void union_set(int i, int j){
        int x = parent(i), y = parent(j);
        if(rank[x] > rank[y]) p[y] = x;
        else {
            p[x] = y;
            if(rank[x] == rank[y]) rank[y]++;
        }
    }
};

vector<bool> visited;
int maximum,dest;
bool dfs(int p){
    visited[p] = true;
    if(p == dest) return true;
    for(int i = 0; i < v[p].size(); i++){
        int child = v[p][i].first;
        if(!visited[child]){
            if(dfs(child)){
                maximum = max(maximum,v[p][i].second);
                return true;
            }
        }
    }
}

int main(){
    int t = 0;
    while(cin >> n >> m >> q && n){
        if(t) cout << endl;
        e.clear();
        while(m--){
            int x,y,z;
            cin >> x >> y >> z;
            x--;y--;
            e.push_back({{x,y},z});
        }
        auto comp = [](pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
                            if(a.second < b.second) return true;
                            return false;
                        };
        sort(e.begin(),e.end(),comp);
        int cnt = 0;
        union_find u(n);
        v.clear();
        v.resize(n);
        for(int i = 0; i < e.size() && cnt < n-1; i++){
            int x = e[i].first.first, y = e[i].first.second;
            if(u.parent(x) != u.parent(y)){
                 v[x].push_back({y,e[i].second});
                 v[y].push_back({x,e[i].second});
                 u.union_set(x,y);
                 cnt++;
            }
        }
        cout << "Case #" << ++t << "\n";
        while(q--){
            int x;
            cin >> x >> dest;
            x--;dest--;
            visited.clear();
            visited.resize(n);
            maximum = INT_MIN;
            if(dfs(x)) cout << maximum << endl;
            else cout << "no path\n";
        }
    }
    return 0;
}
