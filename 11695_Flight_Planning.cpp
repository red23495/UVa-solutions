#include<bits/stdc++.h>

using namespace std;

struct node{
    int n;
    bool active;
};

vector<int> get_diameter(vector<vector<node>>& v, int root){
    queue<int> q;
    q.push(root);
    int far;
    vector<bool> visited(v.size());
    visited[root] = true;
    while(!q.empty()){
        far = q.front();
        q.pop();
        for(int i = 0; i < v[far].size(); i++){
            node c = v[far][i];
            if(!c.active || visited[c.n]) continue;
            int ch = c.n;
            visited[ch] = true;
            q.push(ch);
        }
    }
    vector<int> parent(v.size());
    parent[far] = -1;
    q.push(far);
    visited.clear();
    visited.resize(v.size());
    visited[far] = true;
    while(!q.empty()){
        far = q.front();
        q.pop();
        for(int i = 0; i < v[far].size(); i++){
            node c = v[far][i];
            if(!c.active || visited[c.n]) continue;
            int ch = c.n;
            visited[ch] = true;
            parent[ch] = far;
            q.push(ch);
        }
    }
    vector<int> path;
    int cur = far;
    while(cur != -1){
        path.push_back(cur);
        cur = parent[cur];
    }
    return path;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        vector<vector<node>> v(n+1);
        for(int i = 0; i < n-1; i++){
            int x,y;
            cin >> x >> y;
            v[x].push_back({y,true});
            v[y].push_back({x,true});
        }
        vector<int> diam = get_diameter(v,1);
        int solution = diam.size() - 1;
        int cut_a,cut_b,add_a,add_b;
        //for(auto x: diam) cout << x << ' '; cout << endl;
        for(int i = 1; i < diam.size(); i++){
            int a = diam[i-1], b = diam[i];
            for(node& x: v[a]){
                if(x.n == b) x.active = false;
            }
            for(node& x: v[b]){
                if(x.n == a) x.active = false;
            }
            vector<int> left_diam = get_diameter(v,a);
            vector<int> right_diam = get_diameter(v,b);
            int new_sol = max(ceil((left_diam.size()-1.0)/2.0)
                              +ceil((right_diam.size()-1.0)/2.0)+1,
                              max(left_diam.size()-1.0,right_diam.size()-1.0));
            if(new_sol < solution){
                solution = new_sol;
                cut_a = a;
                cut_b = b;
                add_a = left_diam[left_diam.size()/2];
                add_b = right_diam[right_diam.size()/2];
            }
            for(node& x: v[a]){
                if(x.n == b) x.active = true;
            }
            for(node& x: v[b]){
                if(x.n == a) x.active = true;
            }
        }
        cout << solution << '\n' << cut_b << ' ' << cut_a << '\n' << add_b << ' ' << add_a << endl;
    }
    return 0;
}
