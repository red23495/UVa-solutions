#include<bits/stdc++.h>

using namespace std;

struct node{
    int u,v,c;
};

int n,m;
vector<int> cost,dist;
vector<node> e;
vector<bool> cycle;

void bellman_ford(int a){
    dist.clear();
    dist.resize(n,INT_MAX);
    dist[a] = 0;
    for(int i = 0; i < n-1; i++){
        //bool change = false;
        for(int j = 0; j < e.size(); j++){
            int s = e[j].u, d = e[j].v, w = e[j].c;
            //cout << s << ' ' << d << ' ' << w <<endl;
            if(dist[s] == INT_MAX) continue;
            int nw = w+dist[s];
            if(dist[d] > nw){
                dist[d] = nw;
                //change = true;
            }
        }
        //if(!change) return;
    }
    cycle.clear();
    cycle.resize(n);
    for(int j = 0; j < e.size(); j++){
        int s = e[j].u, d = e[j].v, w = e[j].c;
        //cout << s << ' ' << d << ' ' << w <<endl;
        if(dist[s] == INT_MAX) continue;
        int nw = w+dist[s];
        if(dist[d] > nw){
            dist[d] = nw;
            cycle[d] = true;
            //change = true;
        }
    }
}

int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int test = 1;
    while(cin >> n){
        cout << "Set #" << test++<< endl;
        cost.clear();
        cost.resize(n);
        for(int& x: cost) cin >> x;
        e.clear();
        cin >> m;
        while(m--){
            int u,v;
            cin >> u >> v;
            u--;v--;
            int c = cost[v]-cost[u];
            c = c*c*c;
            e.push_back({u,v,c});
        }
        int q;
        cin >> q;
        if(!n) continue;
        bellman_ford(0);
        while(q--){
            int x;
            cin >> x;
            x--;
            int ans = dist[x];
            if(ans == INT_MAX || ans < 3 || cycle[x]) cout << "?\n";
            else cout << ans << endl;
        }
    }
    return 0;
}
