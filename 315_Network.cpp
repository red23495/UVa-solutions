#include<bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> v;
vector<int> parent,cur,low;
vector<bool> point,visited;
int cnt,rootchild;
void breakpoints(int p){
    cur[p]=low[p]=cnt++;
    visited[p] = true;
    for(int i = 0; i < v[p].size(); i++){
        int child = v[p][i];
        if(!visited[child]){
            parent[child] = p;
            if(p == 0) rootchild++;
            breakpoints(child);
            if(low[child] >= cur[p]) point[p] = true;
            low[p] = min(low[p],low[child]);
        }
        else if(child != parent[p])
            low[p] = min(low[p],cur[child]);
    }
}

void fix(){
    if(rootchild < 2) point[0] = false;
}

int result(){
    int c = 0;
    for(int i = 0; i < n; i++){
        if(point[i]) c++;
    }
    return c;
}

int main(){
    while(cin >> n && n){
        v.clear();
        v.resize(n);
        string s;
        while(cin.peek() == 10) cin.ignore();
        while(true){
            getline(cin,s);
            stringstream ss(s);
            int p,q;
            ss >> p;
            if(p == 0) break;
            p--;
            while(ss >> q){
                v[p].push_back(--q);
                v[q].push_back(p);
            }
        }
        cnt = rootchild = 0;
        parent.clear();
        cur.clear();
        low.clear();
        parent.resize(n);
        cur.resize(n);
        low.resize(n);
        point.clear();
        visited.clear();
        point.resize(n);
        visited.resize(n);
        parent[0] = -1;
        breakpoints(0);
        fix();
        cout << result() << endl;
    }
    return 0;
}
