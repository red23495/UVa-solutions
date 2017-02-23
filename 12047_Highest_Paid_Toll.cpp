#include<bits/stdc++.h>

using namespace std;
using ii = pair<int,int>;
using iii = pair<ii,int>;
int n,m,s,t,p;
vector<vector<ii>> v1,v2;
vector<iii> e;

void dikjstra(int a,vector<int>& cost,vector<int>& toll,vector<vector<ii>>& v){
    cost.clear();
    cost.resize(n,INT_MAX);
    toll.clear();
    toll.resize(n,-1);
    priority_queue<iii> pq;
    pq.push({{0,-1},a});
    while(!pq.empty()){
        iii p = pq.top(); pq.pop();
        int x = p.second, w = p.first.first, wc = p.first.second;
        if(w < cost[x]){
            cost[x] = w;
            toll[x] = wc;
            for(int i = 0; i < v[x].size(); i++){
                int nwc = max(wc,v[x][i].second);
                int d = w+v[x][i].second;
                pq.push({{d,nwc},v[x][i].first});
            }
        }
    }
}

int main(){
    int test;
    cin >> test;
    while(test--){
        cin >> n >> m >> s >> t >> p;
        s--;t--;
        v1.clear();
        v2.clear();
        v1.resize(n);
        v2.resize(n);
        e.clear();
        while(m--){
            int u,v,c;
            cin >> u >> v >> c;
            u--;v--;
            v1[u].push_back({v,c});
            v2[v].push_back({u,c});
            e.push_back({{u,v},c});
        }
        vector<int> cost1,cost2,toll1,toll2;
        dikjstra(s,cost1,toll1,v1);dikjstra(t,cost2,toll2,v2);
        int ans = -1;
        for(int i = 0; i < e.size(); i++){
            int u = e[i].first.first, v = e[i].first.second, c = e[i].second;
            if(cost1[u] == INT_MAX || cost2[v] == INT_MAX) continue;
            if(cost1[u]+cost2[v]+c <= p) ans = max(ans,max(c,max(toll1[u],toll2[v])));
        }
        cout << ans << endl;
    }
    return 0;
}
