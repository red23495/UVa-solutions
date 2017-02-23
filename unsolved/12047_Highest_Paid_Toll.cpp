#include<bits/stdc++.h>

using namespace std;
using ii = pair<int,int>;
using iii = pair<ii,int>;
int n,m,s,t,p;
vector<vector<ii>> v1,v2;
vector<iii> e;
priority_queue<ii> pq;
void dikjstra(int a, vector<int>& cost, vector<vector<ii>>& v){
    cost.clear();
    cost.resize(n,INT_MAX);
    cost[a] = 0;
    pq.push({0,a});
    int cnt = 0;
    vector<bool> visited(n);
    //visited[a] = true;
    while(!pq.empty()){
        if(cnt == n+1) return;
        ii p = pq.top();pq.pop();
        int x = p.second,w = p.first;
        if(cost[x] < w) continue;
            if(!visited[x]){cnt++;visited[x] = true;}
            for(int i = 0; i < v[x].size(); i++){
            int w = cost[x]+v[x][i].second;
            if(w < cost[v[x][i].first]){
                cost[v[x][i].first] = w;
                pq.push({w,v[x][i].first});
            }
        }
    }
    //cout << cnt << endl;
}

int main(){
    int test;
    scanf("%d",&test);
    while(test--){
        scanf("%d%d%d%d%d",&n,&m,&s,&t,&p);
        s--;t--;
        v1.clear();
        v2.clear();
        e.clear();
        v1.resize(n);
        v2.resize(n);
        while(m--){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            u--;v--;
            v1[u].push_back({v,c});
            v2[v].push_back({u,c});
            e.push_back({{u,v},c});
        }
        vector<int> cost1,cost2;
        dikjstra(s,cost1,v1);dikjstra(t,cost2,v2);
        int ans = -1;
        for(auto& x: e){
            int u = x.first.first, v = x.first.second, c = x.second;
            if(cost1[u] == INT_MAX || cost2[v] == INT_MAX) continue;
            if((cost1[u]+cost2[v]+c) <= p) ans = max(c,ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}
