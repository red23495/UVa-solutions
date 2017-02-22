#include<bits/stdc++.h>

using namespace std;

int n,e,t;

using ii = pair<int,int>;
vector<vector<ii>> v;

int main(){
    int test;
    cin >> test;
    while(test--){
        cin >> n >> e >> t;
        v.clear();
        v.resize(n);
        int m;
        cin >> m;
        while(m--){
            int x,y,z;
            cin >> x >> y >> z;
            x--;y--;
            v[y].push_back({x,z});
        }
        /*for(int i = 0; i < n; i++){
            cout << i << ":";
            for(int j = 0; j < v[i].size(); j++){
                cout << v[i][j].first << ' ';
            }
            cout << endl;
        }*/
        priority_queue<ii,vector<ii>,greater<ii>> pq;
        vector<int> cost(n,INT_MAX);
        e--;
        pq.push({0,e});
        while(!pq.empty()){
            ii p = pq.top();pq.pop();
            int b = p.first, a = p.second;
            //cout << a << ' ' << b << endl;
            if(cost[a] > b){
                cost[a] = b;
                for(int i = 0; i < v[a].size(); i++){
                    //cout << v[a][i].first << endl;
                    pq.push({b+v[a][i].second,v[a][i].first});
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(cost[i] <= t) ans++;
            //cout << i << ' ' << cost[i] << endl;
        }
        cout << ans << endl;
        if(test) cout << endl;

    }
    return 0;
}
