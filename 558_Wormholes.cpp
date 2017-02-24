#include<bits/stdc++.h>

using namespace std;

struct node{
    int u,v,w;
};

int n,m;
vector<node> v;
vector<int> dist;
bool wormhole(){
    for(int i = 0; i < m; i++){
        if(dist[v[i].u] == INT_MAX) continue;
        if(dist[v[i].v] > dist[v[i].u]+v[i].w) return true;
    }
    return false;
}
int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int test;
    cin >> test;
    while(test--){
        v.clear();
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            int u,x,w;
            cin >> u >> x >> w;
            v.push_back({u,x,w});
        }
        dist.clear();
        dist.resize(n,INT_MAX);
        dist[0] = 0;
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < m; j++){
                if(dist[v[j].u] == INT_MAX) continue;
                dist[v[j].v] = min(dist[v[j].v],dist[v[j].u]+v[j].w);
            }
        }
        if(wormhole()) cout << "possible\n";
        else cout << "not possible\n";
    }
    return 0;
}
