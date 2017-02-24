#include<bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> v;
vector<int> cost,dist;
vector<int> ccle;
void bellman_ford(){
    dist.clear();
    dist.resize(n,INT_MIN);
    dist[0] = 100;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < v[j].size(); k++){
                if(dist[j] <= 0 || j == n-1) continue;
                int nw = cost[j] + dist[j];
                dist[v[j][k]] = max(dist[v[j][k]],nw);
            }
        }
    }
}

bool cycle(){
    bool ret = false;
    for(int j = 0; j < n; j++){
        for(int k = 0; k < v[j].size(); k++){
            if(dist[j] <= 0 || j == n-1) continue;
            int nw = cost[j] + dist[j];
            if(nw > dist[v[j][k]]){
                ret = true;
                ccle.push_back(v[j][k]);
            }
        }
    }
    return ret;
}

vector<bool> visited;

bool dfs(int p){
    visited[p] = true;
    if(p == n-1) return true;
    for(int i = 0; i < v[p].size(); i++){
        if(!visited[v[p][i]]){
            if(dfs(v[p][i])) return true;
        }
    }
    return false;
}

bool reachable(){
    for(int i = 0; i < ccle.size(); i++){
        if(dfs(ccle[i])) return true;
    }
    return false;
}

int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    while(cin >> n && n != -1){
        v.clear();
        v.resize(n);
        cost.clear();
        cost.resize(n);
        visited.clear();
        visited.resize(n);
        ccle.clear();
        for(int i = 0; i < n; i++){
            int w,n;
            cin >> w >> n;
            cost[i] = w;
            while(n--){
                cin >> w;
                w--;
                v[i].push_back(w);
            }
        }
        bellman_ford();
        int ans = dist[n-1];
        //cout << ans << endl;
        if(ans > 0 || (cycle() && reachable())) cout << "winnable\n";
        else cout << "hopeless\n";
    }
    return 0;
}
