#include<bits/stdc++.h>

using namespace std;
using ii = pair<int,int>;
struct Node{
    int v , w ;
    Node(){}
    Node(int _w , int _v){
        v = _v , w = _w ;
    }
    bool operator <(const Node &a) const{
        if (w != a.w) return (w > a.w);
        return (v > a.v);
    }
};
int v1[10005][10005][2],v2[10005][10005][2],e[100005][3];
int n,m,s,t,p;
int cost1[10005],cost2[10005];
void dikjstra(int r,int(&cost)[10005],int(&v)[10005][10005][2]){
    for(int i = 1; i <= n; i++) cost[i] = INT_MAX;
    priority_queue<Node> pq;
    pq.push({0,r});
    cost[r] = 0;
    int cnt = 1;
    while(!pq.empty()){
        Node p = pq.top(); pq.pop();
        int x = p.v, w = p.w;
        if(cost[x] < w) continue;
        if(cost[x] == INT_MAX) cnt++;
        if(cnt == n) return;
        for(int i = 1; i <= v[x][0][0]; i++){
            int ch = v[x][i][0], cw = v[x][i][1];
            int nw = cw+w;
            if(nw < cost[ch]){
                cost[ch] = nw;
                pq.push({nw,ch});
            }
        }
    }
}

int main(){
    int test;
    scanf("%d",&test);
    while(test--){
        scanf("%d%d%d%d%d",&n,&m,&s,&t,&p);
        for(int i = 1; i <= n; i++) v1[i][0][0] = v2[i][0][0] = 0;
        int u,v,c;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d",&u,&v,&c);
            v1[u][0][0]++;v2[v][0][0]++;
            v1[u][v1[u][0][0]][0] = v; v1[u][v1[u][0][0]][1] = c;
            v2[v][v2[v][0][0]][0] = u; v2[v][v2[v][0][0]][1] = c;
            e[i][0] = u; e[i][1] = v; e[i][2] = c;
        }
        dikjstra(s,cost1,v1);dikjstra(t,cost2,v2);
        int ans = -1;
        for(int i = 0; i < m; i++){
            u = e[i][0], v = e[i][1], c = e[i][2];
            if(cost1[u] == INT_MAX || cost2[v] == INT_MAX) continue;
            if(cost1[u]+cost2[v]+c <= p) ans = max(ans,c);
        }
        printf("%d\n",ans);
    }
}
