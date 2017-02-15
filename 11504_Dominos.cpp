#include<bits/stdc++.h>

using namespace std;

int m,n,ans,timer;
vector<vector<int>> v;
vector<int> color,in;
map<int,int> dict;
void clear(int p){
    color[p] = -1;
    for(int i = 0; i < v[p].size(); i++){
        if(!color[v[p][i]])clear(v[p][i]);
    }
}

void paint(int p){
    color[p] = timer;
    for(int i = 0; i < v[p].size(); i++){
        int child = v[p][i];
        if(!color[child]) paint(child);
        else dict[color[child]] = timer;
    }
}

int main(){
    int test;
    cin >> test;
    while(test--){
        cin >> n >> m;
        v.clear();
        v.resize(n);
        in.clear();
        in.resize(n);
        color.clear();
        color.resize(n);
        while(m--){
            int x,y;
            cin >> x >> y;
            x--;y--;
            v[x].push_back(y);
            in[y]++;
        }
        ans = 0;
        for(int i = 0; i < n; i++){
            if(!in[i]) {clear(i);ans++;}
        }
        dict.clear();
        for(int i = 0; i < n; i++){
            if(!color[i]){
                ++timer;
                dict[timer] = timer;
                paint(i);
            }
        }
        for(auto &x: dict){
            if(x.first == x.second) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
