#include<bits/stdc++.h>
using namespace std;

list<pair<int,int>> path;
vector<vector<pair<int,bool>>> v;
void euler_path(list<pair<int,int>>::iterator it, int u){
    for(int i = 0; i < v[u].size(); i++){
        if(v[u][i].second){
            int c = v[u][i].first;
            v[u][i].second = false;
            for(auto& x: v[c]){
                if(x.first == u && x.second){
                    x.second = false; break;
                }
            }
            euler_path(path.insert(it,{c,u}),c);
        }
    }
}

int main(){
    int test;
    cin >> test;
    for(int t = 1; t <= test; t++){
        cout << "Case #" << t << endl;
        int n;
        cin >> n;
        v.clear();
        v.resize(51);
        vector<int> degree(51);
        while(n--){
            int a,b;
            cin >> a >> b;
            v[a].push_back({b,true});
            v[b].push_back({a,true});
            degree[a]++;degree[b]++;
        }
        bool is_odd = false;
        int start = -1;
        for(int i = 1; i < 51 && !is_odd; i++){
            if(degree[i]&1) is_odd = true;
            else if(degree[i] && start == -1) start = i;
        }
        if(is_odd){
            cout << "some beads may be lost\n";
            if(t != test) cout << endl;
            continue;
        }
        path.clear();
        euler_path(path.begin(),start);
        for(auto p: path) cout << p.first << " " << p.second << endl;
        if(t != test) cout << endl;
    }
    return 0;
}
