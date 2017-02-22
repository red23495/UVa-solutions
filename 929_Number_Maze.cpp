#include<bits/stdc++.h>

using namespace std;
using ii = pair<int,int>;
using iii = pair<int,ii>;
int m,n;
vector<vector<int>> v,cost;


void process(int i, int j, int d, priority_queue<iii,vector<iii>,greater<iii>>& pq){
    if(i < 0 || i >= n || j < 0 || j >= m || d + v[i][j] > cost[i][j]) return ;
    pq.push({d+v[i][j],{i,j}});
}

int main(){
    int test;
    cin >> test;
    while(test--){
        cin >> n >> m;
        v.clear();
        v.resize(n,vector<int>(m));
        for(auto& x: v){
            for(auto& y: x) cin >> y;
        }
        cost.clear();
        cost.resize(n,vector<int>(m,INT_MAX));
        priority_queue<iii,vector<iii>,greater<iii>> pq;
        pq.push({v[0][0],{0,0}});
        int ans = 0;
        while(!pq.empty()){
            iii p = pq.top();
            pq.pop();
            int x = p.second.first, y = p.second.second, c = p.first;
            if(x == n-1 && y == m-1){ans = c; break;}
            if(cost[x][y] > c){
                cost[x][y] = c;
                process(x-1,y,c,pq);
                process(x+1,y,c,pq);
                process(x,y-1,c,pq);
                process(x,y+1,c,pq);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
