#include<bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;

int n,m,s,t;
vector<vector<ii>> v;

int main(){
    int test;
    cin >> test;
    for(int tt = 1; tt <= test; tt++){
        cin >> n >> m >> s >> t;
        v.clear();
        v.resize(n);
        while(m--){
            int x,y,z;
            cin >> x >> y >> z;
            v[x].push_back({y,z});
            v[y].push_back({x,z});
        }
        priority_queue<ii,vector<ii>,greater<ii>> pq;
        vector<int> cost(n,INT_MAX);
        pq.push({0,s});
        int ans = -1;
        while(!pq.empty()){
            ii p = pq.top();pq.pop();
            int a = p.second, b = p.first;
            if(a == t){ans = b; break;}
            if(cost[a] > b){
                cost[a] = b;
                for(int i = 0;i < v[a].size(); i++){
                    pq.push({b+v[a][i].second,v[a][i].first});
                }
            }
        }
        cout << "Case #" << tt << ": ";
        if(ans == -1) cout << "unreachable" << endl;
        else cout << ans << endl;
    }
    return 0;
}
