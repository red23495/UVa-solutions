#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<int>> v;
vector<int> cur,low,parent,child;
vector<bool> point,visited;
int _time;

int cnt(int p){
    int c = 0;
    visited[p] = true;
    for(int i = 0; i < v[p].size(); i++){
        if(!visited[v[p][i]]){
            c++;
            cnt(v[p][i]);
        }
    }
    return c;
}

void breakpoints(int p){
    low[p] = cur[p] = _time++;
    visited[p] = true;
    for(int i = 0; i < v[p].size(); i++){
        int ch = v[p][i];
        if(!visited[ch]){
            parent[ch] = p;
            breakpoints(ch);
            if(cur[p] <= low[ch]){
                point[p] = true;
                child[p]++;
            }
            low[p] = min(low[p],low[ch]);
        }
        else if(ch != parent[p]){
            low[p] = min(low[p],cur[ch]);
        }
    }
}

int main(){
    while(cin >> n >> m && n){
        v.clear();
        v.resize(n);
        int x,y;
        while(cin >> x >> y && x != -1){
            v[x].push_back(y);
            v[y].push_back(x);
        }
        _time = 0;
        cur.clear();low.clear();parent.clear();point.clear();visited.clear();
        cur.resize(n);low.resize(n);parent.resize(n);point.resize(n);visited.resize(n);
        child.clear();child.resize(n);if(n)child[0] = -1;
        breakpoints(0);
        if(child[0] > 1) point[0] = true;
        vector<pair<int,int>> ans;
        for(int i = 0; i < n; i++){
            if(point[i]){
                visited.clear();
                visited.resize(n);
                ans.push_back({i,child[i]+1});
            }
            else ans.push_back({i,1});
        }
        sort(ans.begin(),ans.end(),[](pair<int,int>x,pair<int,int>y){if(x.second > y.second)return true;else if(x.second == y.second && x.first < y.first)return true;return false;});
        for(int i = 0; i < m; i++){
            cout << ans[i].first << ' ' << ans[i].second << endl;
        }
        cout << endl;
    }
    return 0;
}
